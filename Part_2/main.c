// lab1 question 1 derivative of sine_intr.c Sine generation using sin() function
#include <math.h>
#include "DSK6713_AIC23.h"	                // codec support
#include "sine_table.h"						// data of sine in seperate header file (32)
#include "sine_table_1024.h"
#include "sine_table_512.h"
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ;	        //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
//#define table_size 1024
#define LEFT 0
#define RIGHT 1
union {Uint32 uint; short channel[2]}  AIC23_data;

Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; // select input
short table_size = 1024;
short loop = 0;
short loopr = 0;    //the temp value to hold the index value for the cosine function

float shift =0;
float test = 750;
float test2 = 16000;

short gain = 1;               	 	   //for slider
float delta;

//short frequency_delta_calculation = round(250/16000)*table_size ;               	    //for slider
//desired frequency / sampling frequency * table size
//short frequency = 2;
interrupt void c_int11()
{
	AIC23_data.channel[RIGHT] = sinetable1024[loopr];
	AIC23_data.channel[LEFT] = sinetable1024[loop];
	output_sample(AIC23_data.uint);

	shift  = round(table_size / 4) ;
	delta = round( (test/test2) * table_size );
	loop += delta;                   //incr frequency index
	loopr = loop + shift;
	loop = loop % table_size ;
	loopr = loopr %table_size;		 //modulo 32 to reinit index

  return;
}

void main()

{
  comm_intr();
  while(1);
}
