/* 
  System supplied definitions 
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 User supplied definitions 
*/

#include "power.h"
#include "libresistance.h"
#include "component.h"

#define MAX_CHARS_IN_NUMBER                  12
#define MAX_REPLACING_RESISTORS               3
#define MAX_TEXT_LEN                         60
#define MAX_NBR_OF_TEXTS                     16
#define MAX_COMPONENTS                        3
#define MIN_COMPONENTS                        0
#define SERIAL_CONN                        "S\0"
#define PARALLEL_CONN                      "P\0"
#define VALID_INT_CHARS                    "+01234567890-"
#define VALID_FLT_CHARS                    "+01234567890-Ee."


int main(void)
{
  /*
    Good old George Bool!
  */
  
  typedef enum {FALSE = 0, TRUE} boolean;

  float voltage, resistance, pwr;
  float *resistors_p;
  int components = 0;
  int i, replacing_resistors;
  boolean ok_components = FALSE;
  char wiring;


  /*    
   Here are all the messages to be displayed on the screen defined.
  */
  
  const char *the_texts[MAX_NBR_OF_TEXTS] =
    {"Ange spänningskälla i V: ",
     "Ange koppling[S | P]: ",
     "Antal komponenter: ",
     "Komponent 1 i ohm: ",
     "Komponent 2 i ohm: ",
     "Komponent 3 i ohm: ",
     "Ersättningsresistans: ",
     " ohm",
     "Effekt: ",
     " W",
     "Ersättningsresistanser i E12-serien kopplade i serie: ",
     "S[erie] eller P[arallell] måste anges!",
     "Otillåtet flyttal angivet!",
     "Otillåtet heltal angivet!",
     "Antal komponenter måste ligga i intervallet [0, 3]!",
     "Inga resistanser angivna, adjö!"
      };

    
  char a_value[MAX_CHARS_IN_NUMBER+1];

  
  float input_a_float(char *info_text)
  /*
    ####################################################################
     This function prompts for input of a floating point number
     and return the value.
     
     The value is entered as a string and converted to a float.
     Some rudimentary validation is performed on the entered value.
     The accepted characters are defined in: VALID_FLT_CHARS.

     However, this does not give a full syntax check on the entered float!

     Name:  input_a_float

     Parameters:  info_text         The prompt string

     Return: the entered value as a float.
   ######################################################################
  */
    
  {
    boolean ok_float = FALSE;

    /* 
       Keep looping until there is a value that 
       passed the implemented validations.
    */   
    while(!ok_float)
    {	
       /*
          Prompt for a value and read it. 
       */
        printf("%s", info_text);
        scanf("%s", a_value);
	
	/* Check if there are any illegal charaters. */
	ok_float = (strspn( a_value, VALID_FLT_CHARS) == strlen( a_value));

	/* 
           If an invalid character is found, print an error message
           and try again.
	*/	
        if (!ok_float)
	  printf("%s\n", (char *) the_texts[12]);	
    }
    /*    printf("ok_float: %i\n", ok_float); */

    /* Convert the string to float and return. */
    return atof(a_value);
  }


  int input_an_integer(char *info_text)
  /* 
   ####################################################################
     This function prompts for input of an integer number
     and return the value.
     
     The value is entered as a string and converted to an int.
     Some rudimentary validation is performed on the entered value.
     The accepted characters are defined in: VALID_INT_CHARS.

     Name:  input_a_int

     Parameters:  info_text         The prompt string

     Return: the entered value as a int.
   ###################################################################### 
   */
    
  {
    boolean ok_int = FALSE;
    
    /* 
       Keep looping until there is a value that 
       passed the implemented validations.
    */       
    while(!ok_int)
    {
        /*
          Prompt for a value and read it. 
        */  
        printf("%s", info_text);
        scanf("%s", a_value);

	/* 
         Check if there are any illegal charaters.
        */	
	ok_int = (strspn( a_value, VALID_INT_CHARS) == strlen( a_value));

        /* 
          If an invalid character is found, print an error message
          and try again.
        */	
        if (!ok_int)
	  printf("%s\n", (char *) the_texts[13]);
    }
    
    /*
       Convert the string to int and return. 
    */    
    return atoi(a_value);
  }


  char wiring_type(char *info_text)
  /* 
   ####################################################################
     This function prompts for input of the characters 'S' or 'P'
     in order to determine if the resistors are connected 
     in serial [S] or paralell [P]. 

     The function keeps prompting until any of the desired characters are 
     entered. 

     Name:  wiring_type

     Parameters:  info_text         The prompt string

     Return: The character 'S' or 'P'.
   ######################################################################  
  */
    
  {
    char conn_type[2];
    boolean S_or_P_response = FALSE, serial, parallel; 

    /* 
       Keep looping until there is a 
       'S' or 'P' given. 
    */   
    while (!S_or_P_response)
    {
      /* 
        Prompt for a value and read it.
      */    
      printf("%s", info_text);
      scanf("%s", conn_type);
      
      /*
         We only accept 'P' or 'S'. 
         Check what we got!
      */
      serial   = !(boolean) strcmp(conn_type, SERIAL_CONN);
      parallel = !(boolean) strcmp(conn_type, PARALLEL_CONN);

      S_or_P_response = (serial || parallel);

      /*
        It not 'S' or 'P' display error
        message and try again!
      */     
      if (!S_or_P_response)
	printf("%s\n", (char *) the_texts[11]);
      
     }
    
    /*
       Return the given character
    */
    return(conn_type[0]);
   }
    
  /* 
   ########################## main () ################################### 
  */
 
  /*
     Get the voltage.
  */
       
  voltage = input_a_float((char *) the_texts[0]);

  /*
     Get wiring of the resistors.
  */
  
  wiring =  (char ) wiring_type((char *) the_texts[1]);

  /*
     Get number of components, but only accept
     when in the range [0, 3].
  */

  while (!ok_components)
   {
      components = input_an_integer((char *) the_texts[2]);
      ok_components = (components >= MIN_COMPONENTS && components <= MAX_COMPONENTS);

      if (!ok_components)
	  printf("%s\n", (char *) the_texts[14]);      
   }

  /*
     No point in continuing if
     no resistors are given!
   */  
  if(components == 0)
  {
    printf("%s\n", (char *) the_texts[15]);
    return -1;
  }

  /*
    Allocate space for the resistors
    and assign values to them.
  */
  resistors_p = (float *) malloc(components*sizeof(float));

  for (i = 0; i < components; i++)
    *(resistors_p + i) = input_a_float((char *) the_texts[i+3]);
  
  resistance = calc_resistance(components, wiring, resistors_p);
  pwr        = calc_power_r(voltage, resistance);
  
  free(resistors_p);

  printf("%s%.0f%s\n", (char *) the_texts[6],  resistance, (char *) the_texts[7]);
  printf("%s%.2f%s\n", (char *) the_texts[8],  pwr, (char *) the_texts[9]);

  replacing_resistors = e_resistance( resistance, resistors_p );
  printf("%s", (char *) the_texts[10] );
  
  for (i = 0; i <  replacing_resistors; i++)
  {
     printf("%.0f",  *(resistors_p + i) );
     if (i <  replacing_resistors - 1)
       printf(", ");
  }

   printf("\n");  
    
  return 0;
  
}
