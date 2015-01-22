#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <../include/resistance.h>

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

int main( int argc, const char* argv[] )
{
  TestCase1();
  TestCase2();
  printf("Test was ok\n");
}

