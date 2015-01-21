


float calc_resistance(int count, char conn, float *array)
{
  float retVal = 0;

  if ((count == 0) || (array == 0))
    return 0; // Avoid divide by zero in parallel calculation

  int i = 0;
  if (conn == 'P')
  {
    float tmpSum = 0;
    for (i = 0; i < count; i++)
    {
      if (array[i] < 0.000001)
	return 0; // Bail out to avoid crash!

      tmpSum += 1 / array[i];
    }

    retVal = 1 / tmpSum;
  }
  else (conn == 'S')
  {
    for (i = 0; i < count; i++)
    {
      retVal += array[i];      
    }
  }
  else
  {
    return -1.0; // Returning -1 in float. A bit strange, but according to the specification...
  }

  return retVal;
}
