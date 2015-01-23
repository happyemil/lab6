#include <stdio.h>
#include "libpower.h"


int main(){
	float res = 0.0;
	float res2 = 0.00;
	res = calc_power_i(4,2);
	res2 = calc_power_r(10, 5);
	printf("Test calc power i: %4.2f \n", res);
	printf("Test calc power r: %4.2f \n", res2);
	return 0;
}
