// lab1 question 1 derivative of sine_intr.c Sine generation using sin() function
#include <math.h>
#include "DSK6713_AIC23.h"	                // codec support
//#include "sine_table.h"						// data of sine in seperate header file (32)
#include "sine_table_1024.h"
//#include "sine_table_512.h"
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ;	        //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
#define sample_freq 16000

//#define table_size 1024
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; // select input
short table_size = 1024;
short loop = 0;


/*short sine_table[32]={0,195,383,556,707,831,924,981,1000,
					 981,924,831,707,556,383,195,
					 0,-195,-383,-556,-707,-831,-924,-981,-1000,
                   -981,-924,-831,-707,-556,-383,-195};//sine data */

short gain = 1;               	 	   //for slider
short delta = 0;
float desired_freq = 250;
interrupt void c_int11()
{
	delta = round( (desired_freq/sample_freq) * table_size );
	output_left_sample(sinetable1024[loop]*gain);//output scaled value
			 loop += delta;                   //incr frequency index
			 loop = loop % table_size ;                    //modulo 32 to reinit index
  return;
}

void main()
{
  comm_intr();
  while(1);
}
