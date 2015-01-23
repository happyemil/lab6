#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <resistance.h>
#include <libcomponent.h>

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
      printf("Replacements from E12: %f %f %f\n", *resultingResistors++, *resultingResistors++, *resultingResistors);
      
    }

}

int main( int argc, const char* argv[] )
{
  TestCase1();
  testLibComponent();
}

