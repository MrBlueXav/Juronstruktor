/**
 ******************************************************************************
 * File Name          	: sample_player.h
 * Author				: Xavier Halgand
 * Date               	: aout 2014
 * Description        	:
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef JURONSTRUKTOR_SYNTH_SAMPLE_PLAYER_H_
#define JURONSTRUKTOR_SYNTH_SAMPLE_PLAYER_H_
/*-------------------------------------------------------------------------------------------------------------*/
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "samples.h"
#include "CONSTANTS.h"
/*----------------------------------------------------------------------------*/
typedef struct
{
	bool		trig;
	int32_t		idx;
	float_t		float_idx;
	float_t		float_incr;
	float_t 	amp;	// should be <= 1 for normal sound output
	float_t		last_amp;
	Sample_t*	sample_p;
	float_t 	out;	// output sample

} Splayer_t;

/* Exported functions ------------------------------------------------------- */

void 		Splayer_init(Splayer_t* op, float_t amp, const Sample_t* smp);
void 		Splayer_trig(Splayer_t* op);
void 		Splayer_setSample(Splayer_t* op, const Sample_t* smp);
float_t 	SplayerSampleCompute( Splayer_t* op);
void 		Splayer_slow(uint8_t val);
float_t 	SplayerSampleCompute2( Splayer_t* op);


/*-------------------------------------------------------------------------------------------------------------*/
#endif /* JURONSTRUKTOR_SYNTH_SAMPLE_PLAYER_H_ */
