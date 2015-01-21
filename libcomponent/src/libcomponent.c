#include "include/libcomponent.h"

int e_resistance(float orig_resistance, float *res_array)
{
  float closest_distance,res1,res2,res3,diff;
  float E12_Array[13] = {0,10,12,15,18,22,27,33,39,47,56,68,82};
  int i,j,k;
  
  closest_distance = orig_resistance;
  for (i=0;i<13;i++)
    for (j=0;j<13;j++)
      for (k=0;k<13;k++)
	{
	  diff = orig_resistance - E12_Array[i]-E12_Array[j]-E12_Array[k];
	  if (diff<0)
	    diff = E12_Array[i]+E12_Array[j]+E12_Array[k]-orig_resistance;
	  if (diff == 0)
	    {
	      *res_array++ = E12_Array[i];
	      *res_array++ = E12_Array[j];
	      *res_array = E12_Array[k];
	      int count=0;
	      if (i==0)
		count++;
	      if (j==0)
		count++;
	      if (k==0)
		count++;
	      return count;
	    }
	  if (diff<closest_distance)
	    {
	      printf("%f.1\n",diff);
	      closest_distance = diff;
	      res1 = E12_Array[i];
	      res2 = E12_Array[j];
	      res3 = E12_Array[k];
	    }
	}
  *res_array++ = res1;
  *res_array++ = res2;
  *res_array = res3;

  int count=0;
  if (res1==0)
    count++;
  if (res2==0)
    count++;
  if (res3==0)
    count++;
  return count;
}
