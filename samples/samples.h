/*
 * samples.h
 *
 *  Created on: 22 août 2014
 *      Author: CNous
 */

#ifndef JURONSTRUKTOR_SAMPLES_SAMPLES_H_
#define JURONSTRUKTOR_SAMPLES_SAMPLES_H_

#include <math.h>
#include <stdint.h>
/*----------------------------------------------------------------------------*/
#define SAMPLES_NUMBER	25

/*----------------------------------------------------------------------------*/
typedef struct
{

		int32_t 	size; // number of 16bits samples
		int16_t*	array_p;

} Sample_t;

#endif /* JURONSTRUKTOR_SAMPLES_SAMPLES_H_ */
