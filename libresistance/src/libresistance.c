


float calc_resistance(int count, char conn, float *array)
{
  float retVal = 0;

  if (count == 0)
    return 0; // Avoid divide by zero in parallel calculation

  int i = 0;
  if (conn == 'p')
  {
    float tmpSum = 0;
    for (i = 0; i < count; i++)
    {
      tmpSum += 1 / array[i];
    }

    retVal = 1 / tmpSum;
  }
  else
  {
    for (i = 0; i < count; i++)
    {
      retVal += array[i];      
    }
  }

  return retVal;
}
