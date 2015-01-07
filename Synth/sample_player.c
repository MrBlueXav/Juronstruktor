/**
 ******************************************************************************
 * File Name          	: sample_player.c
 * Author				: Xavier Halgand
 * Date               	: aout 2014
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

#include "sample_player.h"

//-----------------------------------------------------------------------------------------

Splayer_t 	player1;
Splayer_t 	player2;
int8_t 		splayer_turn = 0; // which player use ?

//-----------------------------------------------------------------------------------------

void Splayer_slow(uint8_t val)
{
	float_t incf = (2 - 0.5f) * val / MIDI_MAX + 0.5f;
	player1.float_incr = incf;
	player2.float_incr = incf;
}
//-----------------------------------------------------------------------------------------
void Splayer_init(Splayer_t* op, float_t amp, const Sample_t* smp)
{
	op->trig = false;
	op->amp = amp;
	op->last_amp = amp;
	op->idx = 0;
	op->float_idx = 0;
	op->float_incr = 1;
	op->out = 0;
	op->sample_p = (Sample_t*)smp;

}
//-----------------------------------------------------------------------------------------
void Splayer_trig(Splayer_t* op)
{
	op->trig = true;
}
//-----------------------------------------------------------------------------------------
void Splayer_setSample(Splayer_t* op, const Sample_t* smp)
{
	op->sample_p = (Sample_t*)smp;
}
//-----------------------------------------------------------------------------------------
float_t SplayerSampleCompute( Splayer_t* op)
{
	float_t z;

	if ( op->trig == false) // if we continue playing the sample...
	{
		if (op->idx >= op->sample_p->size) // if we have reached the end of the sample...
		{
			z = 0; // silence
		} else
		{
			z = (op->sample_p->array_p[op->idx])/32767.0f ;
			(op->idx)++;
		}

	} else // if we restart
	{
		op->idx = 0;
		z = (op->sample_p->array_p[0])/32767.0f ;
		(op->idx)++;
		op->trig = false;
	}
	op->out = op->amp*z;
	return op->out;
}
//-----------------------------------------------------------------------------------------
float_t SplayerSampleCompute2( Splayer_t* op)
{
	int32_t n;
	float_t z;
	float_t	xn; // x(n)
	float_t	xnp1; // x(n+1)
	float_t t;

	t = op->float_idx;

	if ( op->trig == false) // if we continue playing the sample...
	{
		if (t >= op->sample_p->size) // if we have reached the end of the sample...
		{
			z = 0; // silence
		} else
		{
			n = (int32_t)floorf(t);
			xn = (op->sample_p->array_p[n])/32767.0f ;
			xnp1 = (op->sample_p->array_p[n+1])/32767.0f ;
			z = (t -n)*(xnp1 - xn) + xn ;
			op->float_idx += op->float_incr ;
			//(op->idx)++;
		}

	} else // if we restart
	{
		op->float_idx = 0;
		z = (op->sample_p->array_p[0])/32767.0f ;
		op->float_idx += op->float_incr ;
		//(op->idx)++;
		op->trig = false;
	}
	op->out = op->amp*z;
	return op->out;
}
//-----------------------------------------------------------------------------------------
