#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <resistance.h>
#include <libcomponent.h>
#include <libpower.h>

int main( int argc, const char* argv[] )
{
	float U =0.0f;
	char mode;
	float *res_array;
	int count;
	float eResistans = 0;
	int i;
	float *array;
	

	printf("Ange spänningskälla i V: ");
        scanf("%f", &U);

	printf("Ange koppling[S | P]: ");
	scanf (" %c", &mode);

	printf("Antal komponenter: ");
        scanf("%d", &count);
	
	array = (float *)malloc(sizeof(float)*count);
	res_array = (float *)malloc(sizeof(float)*3);
	
	for(i = 0 ; i<count;i++){
		printf("Komponent %d i ohm:",i+1);
        	scanf("%f",&array[i]);
	}
	
	eResistans = calc_resistance(count,mode,array);
	printf("Ersättningsresistans:%.f\n",eResistans); 
	printf("Effekt:%.2fW\n", calc_power_r(U,eResistans));
	
	int componentCount = e_resistance(eResistans, res_array);
	printf("\nComponentcount: %d\n",componentCount);

	printf("Resistor 0: %f\n", res_array[0]);
	printf("Resistor 1: %f\n", res_array[1]);
	printf("Resistor 2: %f\n\n", res_array[2]);
	
printf("Ersättningsresistanser i E12-serien kopplade i serie:");	
	for(i = componentCount-1; i>=0;i--){
		if(i!=componentCount-1){
			printf(", ");
		}		
		printf(" %.f",res_array[i]);		
	}
	
	free(array);
	free(res_array);
	printf("\nTest done\n");
/*
	Written by Per - woop
*/
	
}

