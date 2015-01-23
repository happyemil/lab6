#include <stdlib.h>
#include "../include/libpower.h"

/*
	Övning 6. Bibliotek 2
	skrivet av Per Johansson
*/

/*
	P=U^2/R
*/
float calc_power_r(float volt, float resistance){
	float P = 0.0;
	float R = resistance;
	float U = volt;
	P = (U * U)/R;

	return P;
}

/*
	P=U*I
*/
float calc_power_i(float volt, float current){
	float P = 0.0;
	float U = volt;
	float I = current;
	P = U * I;

	return P;
}
