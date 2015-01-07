/**
 ******************************************************************************
 * File Name          : soundGen.c
 * Author			  : Xavier Halgand
 * Date               :
 * Description        :
 ******************************************************************************
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */


#include "soundGen.h"

/*-------------------------------------------------------*/

#define EPSI				.00002f
//#define MAX_SOUNDS			14 // number - 1 of different sounds (starts at 0)

/*-------------------------------------------------------*/

extern 		Splayer_t player1;
extern 		Splayer_t player2;
extern 		int8_t splayer_turn;

extern const Sample_t* samples[];

extern bool					demoMode;
//extern bool					freeze;

extern Sequencer_t 			seq;
extern NoteGenerator_t 		noteG;

extern Oscillator_t 		filt1_lfo _CCM_;
extern Oscillator_t 		filt2_lfo _CCM_;
extern Oscillator_t 		amp_lfo _CCM_;

extern ResonantFilter 	SVFilter;
extern ResonantFilter 	SVFilter2;
extern float			filterFreq1  ;
extern float			filterFreq2  ;

static bool 		autoFilterON _CCM_;
static bool			delayON _CCM_;
static bool			phaserON _CCM_;
static bool 		chorusON _CCM_;

static float 			vol  _CCM_;
static float			env  _CCM_;


/*===============================================================================================================*/


void DemoMode_toggle(uint8_t val)
{
	if (val == MIDI_MAXi)
	{
		demoMode = !demoMode;
	}
}

/*-------------------------------------------------------*/
void AmpLFO_amp_set(uint8_t val)
{
	amp_lfo.amp = val / MIDI_MAX;
}
/*-------------------------------------------------------*/
void AmpLFO_freq_set(uint8_t val)
{
	amp_lfo.freq = MAX_VIBRATO_FREQ / MIDI_MAX * val;
}
/*-------------------------------------------------------*/
void Filt1LFO_amp_set(uint8_t val)
{
	filt1_lfo.amp = MAX_FILTER_LFO_AMP / MIDI_MAX * val;
}
/*-------------------------------------------------------*/
void Filt1LFO_freq_set(uint8_t val)
{
	filt1_lfo.freq = MAX_VIBRATO_FREQ / MIDI_MAX * val;
}
/*-------------------------------------------------------*/
void Filt2LFO_amp_set(uint8_t val)
{
	filt2_lfo.amp = MAX_FILTER_LFO_AMP / MIDI_MAX * val;
}
/*-------------------------------------------------------*/
void Filt2LFO_freq_set(uint8_t val)
{
	filt2_lfo.freq = MAX_VIBRATO_FREQ / MIDI_MAX * val;
}

/*-------------------------------------------------------*/
void Delay_toggle(void)
{
	if (delayON)
	{
		delayON = false;
		Delay_clean();
	}
	else delayON = true;
}
/*-------------------------------------------------------*/
void Delay_switch(uint8_t val)
{

	if (val > 63)
		delayON = true;
	else
		delayON = false;
}
/*-------------------------------------------------------*/
void toggleFilter(void)
{
	if (autoFilterON) autoFilterON = false;
	else autoFilterON = true;
}
/*-------------------------------------------------------*/
void Filter_Random_switch(uint8_t val)
{
	if (val > 63)
		autoFilterON = true;
	else
		autoFilterON = false;
}
/*-------------------------------------------------------*/
void Chorus_toggle(void)
{
	if (chorusON) chorusON = false;
	else chorusON = true;
}
/*-------------------------------------------------------*/
void Chorus_switch(uint8_t val)
{

	if (val > 63)
		chorusON = true;
	else
		chorusON = false;
}
/*-------------------------------------------------------*/
void Phaser_switch(uint8_t val)
{

	if (val > 63)
		phaserON = true;
	else
		phaserON = false;
}

/*===============================================================================================================*/

void
Synth_Init(void)
{
	vol = env = 1;

	autoFilterON = false;
	chorusON = false;
	delayON = true;
	phaserON = false;

	Delay_init();

	sequencer_init();

	Chorus_init();
	PhaserInit();
	SVF_init();
	filterFreq1 = 0.25f;
	filterFreq2 = 0.25f;

	Splayer_init(&player1, 0.8f, samples[0]);
	Splayer_init(&player2, 0.8f, samples[0]);


	osc_init(&filt1_lfo, 0, 0);
	osc_init(&filt2_lfo, 0, 0);
	osc_init(&amp_lfo, 0, 0);

}
/*---------------------------------------------------------------------------------------*/

void sequencer_newStep_action(void) // User callback function called by sequencer_process()
{



	if ( !((noteG.someNotesMuted) && ((int8_t)rintf(frand_a_b(0.4f , 1)) == 0)) ) // "holes" management in the sequence
	{

		if ( splayer_turn % 2)
		{
			Splayer_setSample(&player1, samples[seq.track1.note[seq.step_idx]]);
			Splayer_trig(&player1);
		} else
		{
			Splayer_setSample(&player2, samples[seq.track1.note[seq.step_idx]]);
			Splayer_trig(&player2);
		}
		splayer_turn++;
	}

	if (autoFilterON)
		SVF_directSetFilterValue(&SVFilter, Ts * 600.f * powf(5000.f / 600.f, frand_a_b(0 , 1)));

	vol = frand_a_b(0.6f , .8f); // slightly random volume for each note
}
/*---------------------------------------------------------------------------------------*/

void sequencer_newSequence_action(void) // User callback function called by sequencer_process()
{
	/* A new sequence begins ... */
	if ((noteG.automaticON || noteG.chRequested))
	{
		seq_sequence_new();
		noteG.chRequested = false;
	}

}
/*===============================================================================================================*/

void make_sound(uint16_t *buf , uint16_t length) // To be used with the Sequencer
{

	uint16_t 	pos;
	uint16_t 	*outp;
	float	 	y = 0;
	float	 	yL, yR ;
	uint16_t 	valueL, valueR;

	outp = buf;

	for (pos = 0; pos < length; pos++)
	{
		/*--- Sequencer actions and update ---*/
		sequencer_process(); //computes f0 and calls sequencer_newStep_action() and sequencer_newSequence_action()

		/*--- Generate waveform ---*/
		y = vol * (SplayerSampleCompute2(&player1) + SplayerSampleCompute2(&player2));

		/*--- Apply filter effect ---*/
		/* Update the filters cutoff frequencies */
		if ((! autoFilterON)&&(filt1_lfo.amp != 0))
			SVF_directSetFilterValue(&SVFilter, filterFreq1 * (1 + OpSampleCompute7bis(&filt1_lfo)));
		if (filt2_lfo.amp != 0)
			SVF_directSetFilterValue(&SVFilter2, filterFreq2 * (1 + OpSampleCompute7bis(&filt2_lfo)));
		y = 0.5f * (SVF_calcSample(&SVFilter, y) + SVF_calcSample(&SVFilter2, y)); // Two filters in parallel

		/*---  Apply delay effect ----*/
		if (delayON) 	y = Delay_compute(y);

		/*---  Apply phaser effect ----*/
		if (phaserON) 	y = Phaser_compute(y);

		/*--- Apply chorus/flanger effect ---*/
		if (chorusON) stereoChorus_compute (&yL, &yR, y) ;
		else yL = yR = y;

		/*--- clipping ---*/
		yL = (yL > 1.0f) ? 1.0f : yL; //clip too loud left samples
		yL = (yL < -1.0f) ? -1.0f : yL;

		yR = (yR > 1.0f) ? 1.0f : yR; //clip too loud right samples
		yR = (yR < -1.0f) ? -1.0f : yR;

		/****** let's hear the new sample *******/

		valueL = (uint16_t)((int16_t)((32767.0f) * yL)); // conversion float -> int
		valueR = (uint16_t)((int16_t)((32767.0f) * yR));

		*outp++ = valueL; // left channel sample
		*outp++ = valueR; // right channel sample
	}

}

