#include <stdio.h>
#include "power.h"

int main()

{
  float volts = 10.0, amps = 4.0, ohms = 1000;
  printf(" Power (U^2/R): %f\n", calc_power_r(volts, ohms));
  printf(" Power (U*I): %f\n", calc_power_i(volts, amps));  

  return 0;

}  
