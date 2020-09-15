// lab1 question 3
#include <math.h>
#include "DSK6713_AIC23.h"	                // codec support
#include "sine_table.h"						// data of sine in seperate header file (32)
#include "sine_table_1024.h"
#include "sine_table_512.h"
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ;	        //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
//#define table_size 1024
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; // select input

#define LEFT 0
#define RIGHT 1
union {Uint32 uint; short channel[2]}  AIC23_data;


short table_size = 1024;
short loop = 0;
short loopm = 0;

float testc = 6000;
float test2 = 16000;
float testm = 400;
short output = 0;
short output2 = 0;

float mod_index = 1.0; //for slider

float gain1 = 1.0;               //for slider
float gain2 = 1.0;
short delta = 0;
short delta2 = 0;

//short frequency_delta_calculation = round(250/16000)*table_size ;               	    //for slider
//desired frequency / sampling frequency * table size
//short frequency = 2;
interrupt void c_int11()
{
	gain2 = mod_index / 100; //for slider index modulation, Ac(gain) stays constant therefore Am(gain2) is changed
	delta = round( (testc/test2) * table_size );
	delta2 = round( (testm/test2) * table_size );
	output2 = round(sinetable1024[loopm]*(gain2/1000)) ; //message output
	output = round(sinetable1024[loop]*(gain1 + output2)); //modulated message
	AIC23_data.channel[RIGHT] = output;
	AIC23_data.channel[LEFT] = sinetable1024[loop];
	output_sample(AIC23_data.uint);

	    //output scaled value
	loop += delta;  				//incr frequency index
	loopm += delta2;				//incr frequency index

	loop = loop % table_size ;      //modulo 32 to reinit index
	loopm = loopm % table_size ;	 //modulo 32 to reinit index
  return;
}

void main()
{
  comm_intr();

  while(1){
	  if (testm > testc){
		  testm = testc / 10;
	  }

  }
}
