/**
 ******************************************************************************
 * File Name          	: midi_interface.c
 * Author				: Xavier Halgand
 * Date               	:
 * Description        	:
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

#include "midi_interface.h"



/*-----------------------------------------------------------------------------*/
void MagicFX(uint8_t val) /* random effects parameters */
{
	if (val == MIDI_MAXi)
	{
		Delay_switch(MIDI_MAXi);
		Delay_time_set(MIDIrandVal());
		DelayWet_set(MIDIrandVal());
		DelayFeedback_set(MIDIrandVal());

		Chorus_switch(MIDI_MAXi);
		ChorusRate_set(MIDIrandVal());
		ChorusSecondRate_set(MIDIrandVal());
		ChorusDelay_set(MIDIrandVal());
		ChorusSweep_set(MIDIrandVal());
		ChorusFeedback_set(MIDIrandVal());
		ChorusMode_switch(MIDIrandVal());
		ChorusFDBsign_switch(MIDIrandVal());

		Phaser_switch(MIDI_MAXi);
		Phaser_Rate_set(MIDIrandVal());
		Phaser_Feedback_set(MIDIrandVal());
		Phaser_Wet_set(MIDIrandVal());
	}
}
/*-----------------------------------------------------------------------------*/

/*******************************************************************************
 * This function is called by USBH_MIDI_Handle(...) from file "usbh_midi_core.c"
 *
 * To fix : The first MIDI event (first 4 bytes) only of the data buffer is processed, but there might be
 * several MIDI events in that 64 bytes buffer....
 *
 * *****************************************************************************/
void MIDI_Decode(uint8_t * outBuf)
{

	uint8_t val = 0;

	if (outBuf[1] != 0x00) start_LED_On(LED_Blue, 8);

	/* If the midi message is a Control Change... */
	if ((outBuf[1] & 0xF0) == 0xB0)
	{
		val = outBuf[3];

		switch(outBuf[2])
		{
		case 3 	: 	seq_tempo_set(val); 		break;	// tempo
		case 13 : 	Volume_set(val); 			break;	// master volume

		case 4  : 	Splayer_slow(val);			break;	// max frequency

		case 67 :	DemoMode_toggle(val);		break;

		case 38 :	MagicFX(val);				break;	// random settings for effects
		case 81 :	MagicFX(val);				break;	//

		case 8 :	Filter1Freq_set(val);		break;	//
		case 9 :	Filter1Res_set(val);		break;	//
		case 53 :	Filter1Freq_set(val);		break;	//
		case 54 :	Filter1Res_set(val);		break;	//
		case 12 :	Filter1Drive_set(val);		break;	//
		case 55 :	Filter1Drive_set(val);		break;	//
		case 56 :	Filter1Type_set(val);		break;	//

		case 23 :	Delay_switch(val);			break;	// Delay ON/OFF
		case 14 :	Delay_time_set(val);		break;	// Delay time
		case 15 :	DelayFeedback_set(val);		break;	// Delay feedback
		case 2 :	DelayWet_set(val);			break;	// Delay wet signal amplitude
		case 40 :	Delay_time_dec(val);		break;
		case 41 :	Delay_time_inc(val);		break;

		case 27 :	Filter_Random_switch(val);	break;	// Filter ON/OFF

		case 28 :	Chorus_switch(val);			break;	// Chorus ON/OFF
		case 37 :	Chorus_reset(val);			break;
		case 18 :	ChorusRate_set(val);		break;	// Chorus rate
		case 22 :	ChorusSecondRate_set(val);	break;	// Chorus relative rate for LFO right
		case 19 :	ChorusDelay_set(val);		break;	// Chorus delay
		case 20 :	ChorusSweep_set(val);		break;	// Chorus sweep
		case 21 :	ChorusFeedback_set(val);	break;	// Chorus feedback
		case 29 :	ChorusMode_switch(val);		break;	// Chorus mode
		case 30 :	ChorusFDBsign_switch(val);	break;	// Chorus fdb sign

		case 24 :	Phaser_switch(val);			break;
		case 102 :	Phaser_Rate_set(val);		break;
		case 103 :	Phaser_Feedback_set(val);	break;
		case 89 :	Phaser_Wet_set(val);		break;

		case 26 :	seq_switchMovingSeq(val);	break;	// toggle sequence mode
		case 25 :	seq_switchMute(val);		break;	// toggle muted notes ("holes")


		case 65 :	Filt1LFO_amp_set(val);		break;	//
		case 66 :	Filt1LFO_freq_set(val);		break;	//

		case 57 :	AmpLFO_amp_set(val);		break;	//
		case 58 :	AmpLFO_freq_set(val);		break;	//

		case 90 :	Filter2Freq_set(val);		break;	//
		case 91 :	Filter2Res_set(val);		break;	//
		case 92 :	Filter2Drive_set(val);		break;	//
		case 93 :	Filter2Type_set(val);		break;	//

		case 105 :	Filt2LFO_amp_set(val);		break;	//
		case 106 :	Filt2LFO_freq_set(val);		break;	//

		case 85 : 	Seq_step_note_set(0, val);		break;
		case 94 :	Seq_step_note_set(4, val);		break;

		case 86 : 	Seq_step_note_set(1, val);		break;
		case 95 :	Seq_step_note_set(5, val);		break;

		case 87 : 	Seq_step_note_set(2, val);		break;
		case 96 :	Seq_step_note_set(6, val);		break;

		case 88 : 	Seq_step_note_set(3, val);		break;
		case 97 :	Seq_step_note_set(7, val);		break;

		}
	}
}
