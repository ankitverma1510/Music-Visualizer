/*
 * math_fun.h
 *
 *  Created on: 02-May-2022
 *      Author: ankit
 */

#ifndef MATH_FUN_H_
#define MATH_FUN_H_

#include <complex.h>

float sqrt(int );

void fft(volatile complex float *, int , volatile complex float *);

int Log2n(int );


complex float power( complex float , int );


#endif /* MATH_FUN_H_ */
