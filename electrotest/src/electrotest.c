#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <resistance.h>

static float randFloat(void)
{
  return (float)rand() / RAND_MAX;
} 

/**
  Verify calc_resistance calculations
 */
static void TestCase1(void)
{
  float resistors[2] = {1.0, 1.0};
  float totalResistance = calc_resistance(2, 
					  'P',
					  resistors);
  assert(totalResistance == 0.5);

  totalResistance = calc_resistance(2, 
				    'S',
				    resistors);
  assert(totalResistance == 2.0);
}

/**
  Verify that calc_resistance can handle bad input data
 */
static void TestCase2(void)
{
  // 0 parallel resistors should be ok
  float resistors[2] = {1.0, 0.0};
  float totalResistance = calc_resistance(0, 
					  'P',
					  resistors);
  assert(totalResistance == 0.0);

  // 1 parallel resistors should be ok
  totalResistance = calc_resistance(1, 
				    'P',
				    resistors);
  assert(totalResistance == 1.0);

  // 2 parallel resistors should not be ok, because 2:nd resistance is 0.0
  totalResistance = calc_resistance(2, 
				    'P',
				    resistors);
  assert(totalResistance == 0.0);

  // 2 serial resistors should not be ok, even if 2:nd resistance is 0.0
  totalResistance = calc_resistance(2, 
				    'S',
				    resistors);
  assert(totalResistance == 1.0);

  // Bad coupling type shall result in -1.0
  totalResistance = calc_resistance(2, 
				    'A',
				    resistors);
  assert(totalResistance == -1.0);

  // Bad coupling pointer
  totalResistance = calc_resistance(2, 
				    'A',
				    NULL);
  assert(totalResistance == -1.0);
}

/**
  Test whole chain with random data.
 */
static void TestCase3(void)
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

int main( int argc, const char* argv[] )
{
  TestCase1();
  TestCase2();
  TestCase3();
}

