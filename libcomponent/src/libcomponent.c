/* Author Emil Käll*/

int e_resistance(float orig_resistance, float *res_array)
{
  float closest_distance,res1,res2,res3,diff;
  float E12_Array[13] = {0,10,12,15,18,22,27,33,39,47,56,68,82};
  int i,j,k;
  
  // Let's create a larger array for all decades, i.e all E12 values
  float fullE12_Array[13+12+12+12+12+1];
  fullE12_Array[0] = 0;
  int decade;
  
  //We loop over the decades
  for (decade=1;decade<6;decade++)
    {
      int whatDecade=1;
      int j;
      //Here we just create a value to multiply with
      for(j=1;j<decade;j++)
	whatDecade *= 10;

      int i=0;
      while(i++<13)
	{
	  //Add to the full array.
	  fullE12_Array[i+(decade-1)*12]=E12_Array[i]*whatDecade;
	}
    }
  //The last megaohm
  fullE12_Array[61]=1000000;

  //Let's set an initial value for closest distance. Assume we start with all three 
  //resistors at 0 ohm
  closest_distance = orig_resistance;
  //Three nested loops tests all possible outcomes
  for (i=0;i<61;i++)
    for (j=0;j<61;j++)
      for (k=0;k<61;k++)
	{
	  //Lets check how close we are
	  diff = orig_resistance - fullE12_Array[i]-fullE12_Array[j]-fullE12_Array[k];
	  //If we are above target we take that diff instead
	  if (diff<0)
	    diff = fullE12_Array[i]+fullE12_Array[j]+fullE12_Array[k]-orig_resistance;
	  if (diff == 0)
	    {
	      //If we get here we're done. Just to assign the values to the result array
	      if (res1 == 0 && res2 == 0)
		{
		  res_array[0] = res3;
		  res_array[1] = 0;
		  res_array[2] = 0;
		}
	      else if (res1 == 0 && res3 == 0)
		{
		  res_array[0] = res2;
		  res_array[1] = 0;
		  res_array[2] = 0;
		}
	      else if (res1 == 0 && res2 != 0 && res3 != 0 )
		{
		  res_array[0] = res2;
		  res_array[1] = res3;
		  res_array[2] = 0;
		}
	      else if (res1 != 0 && res2 == 0 && res3 != 0 )
		{
		  res_array[0] = res1;
		  res_array[1] = res3;
		  res_array[2] = 0;
		}
	      else
		{
		  res_array[0] = res1;
		  res_array[1] = res2;
		  res_array[2] = res3;
		}
	      //Lets se how many resistors in series we use
	      int count=3;
	      if (i==0)
		--count;
	      if (j==0)
		--count;
	      if (k==0)
		--count;
	      return count;
	    }
	  if (diff<closest_distance)
	    {
	      //We got closer. Set that distance as the closest one and update
	      //resistor values
	      closest_distance = diff;
	      res1 = fullE12_Array[i];
	      res2 = fullE12_Array[j];
	      res3 = fullE12_Array[k];
	    }
	}

  //We are out of all for-loops meaning that we didn't find a perfect match,
  //but the closest match is in res1,2,3.
  if (res1 == 0 && res2 == 0)
    {
      res_array[0] = res3;
      res_array[1] = 0;
      res_array[2] = 0;
    }
  else if (res1 == 0 && res3 == 0)
    {
      res_array[0] = res2;
      res_array[1] = 0;
      res_array[2] = 0;
    }
  else if (res1 == 0 && res2 != 0 && res3 != 0 )
    {
      res_array[0] = res2;
      res_array[1] = res3;
      res_array[2] = 0;
    }
  else if (res1 != 0 && res2 == 0 && res3 != 0 )
    {
      res_array[0] = res1;
      res_array[1] = res3;
      res_array[2] = 0;
    }
  else
    {
      res_array[0] = res1;
      res_array[1] = res2;
      res_array[2] = res3;
    }


  //How many resistors did we use?
  int count=3;
  if (res1==0)
    --count;
  if (res2==0)
    --count;
  if (res3==0)
    --count;
  return count;
}


