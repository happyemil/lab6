#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <resistance.h>
#include <libcomponent.h>
#include <libpower.h>

static float randFloat(void)
{
  return (float)rand() / RAND_MAX;
} 

/**
  Test whole chain with random data.
 */
static void TestCase1(void)
{
  const int numRuns = 10;
  const int maxNumResistors = 10;
  const float maxInputResistor = 1000000.0;
  
  int i = 0;
  for (i = 0; i < numRuns; i++)
  {
    char couplingType = (rand() % 2 == 0) ? 'P' : 'S';

    printf("Run[%d]: Coupling:%c\n", i, couplingType);  

    int numResistors = rand() % maxNumResistors;
    int j = 0;
    float *resistors = (float*)malloc(sizeof(float) * numResistors);
    for (j = 0; j < numResistors; j++)
    {
      resistors[j] = randFloat() * maxInputResistor;
      printf("  Resistor[%d]: %f\n", j, resistors[j]); 
    }

    float totalResistance = calc_resistance(numResistors, 
					    couplingType,
					    resistors);

    printf("  Total resistance: %f\n", totalResistance);

    printf("\n");

    free(resistors);
  }
}

void testLibcomponent(void)
{
  const int numRuns = 10;
  const float maxInputResistor = 1000000.0;
  float inputResistor;
  int count=0;

  int i = 0;
  for (i = 0; i < numRuns; i++)
    {
      inputResistor = randFloat() * maxInputResistor;
      printf("Finding resistor replacement for %f Ohms\n",inputResistor);
      float *resultingResistors = (float*)malloc(sizeof(float) * 3);
      count = e_resistance(inputResistor, resultingResistors);
      printf("Number of replacement resistors: %d\n",count);
      printf("Replacements from E12: %f %f %f\n", resultingResistors[0], resultingResistors[1], resultingResistors[2]);
      free(resultingResistors);
      
    }

}

void testLibPower(void){
	float res = 0.0;
	float res2 = 0.0;
	float U = 3.01;
	float I = 2.2;
	float R = 1.75;
	res = calc_power_i(U,I);
	res2 = calc_power_r(U, R);
	
	printf("Libpower test: \n");
	printf("Test calc power P=U*I -> U=%6.4f, I=%6.4f results in P=%6.4fW\n", U, I, res);
	printf("Test calc power P=U^2/R: U=%6.4f, R=%6.4f results in P=%6.4fW\n", U, R, res2);

}

int main( int argc, const char* argv[] )
{
  TestCase1();
  testLibcomponent();
  testLibPower();
}

