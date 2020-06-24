/****************************************************
 *				Abdulilah 	Azzazi					*
 *				--------------------				*
 * 			Oscillatory Motion and Chaos			*
 *													*
 ****************************************************/ 

#include "zDA.h"
#include "zOptions.h"
#include "zMain.h"
#include "zSim.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	//Main Variable
	int i;
	
	SIMOPT sopt;
	PRINTOPT popt;
	SIMOPT *sp = &sopt;
	PRINTOPT *pp = &popt;
	ProgDetails x;
	x.name = "Oscillatory Motion and Chaos";
	x.desc = "a harmonic motion simulator";
	PrintWelcome(&x);

	//Main Initializations
	InitPrintOpt(pp);
	InitSimOpt(sp);
	

	//Main Loop
	do {
		i = Menu();
		switch(i) {
			case 0:
				break;
			case 1:
				Simulate(sopt,popt);
				break;
			case 2:
				while(ReadSimOpt(sp));
				break;
			case 3:
				while(ReadPrintOpt(pp));
				break;
			case 4:
				while(ParameterSweep(sp,pp));
				break;
			default:
				printf("Invalid Input!\n\n");
				i = 1;
				break;
		}
	}while(i);
	return 0;
}
