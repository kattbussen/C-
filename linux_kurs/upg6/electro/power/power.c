
/*
  Author: Göran Andersson, 2015-09-26
  Name: calc_power_r
  
  This function takes two arguments the voltage (Volt) and the resistance (Ohm)
  and calculates the released power of heat (W).

*/

float calc_power_r(float volt, float resistance)  
{  
  return volt*volt/resistance;
}

/*
  Author: Göran Andersson, 2015-09-25
  Name: calc_power_i
  
  This function takes two arguments the voltage (Volt) and the current (Ampere)
  and calculates the released power of heat (W).
  
*/
float calc_power_i(float volt, float current)
{
  return volt*current;
}
