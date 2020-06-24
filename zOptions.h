#ifndef OPTIONS_H
#define	OPTIONS_H

/*	ABDULILAH AZZAZI 900092644 - Last revision March 22, 2013. 
 *
 * Please Customize this to suite your needs :) 
 * ----------------------------------------------
 *This file defines the SIMOPT and PRINTOPT structs
 *SIMOPT:
 * - Handles all inputs to simulation, ie, Giving SIMOPT, mathematically, the simulation should be completed!
 *PRINTOPT:
 *- Handles all outputs from simulation results:
 *	GRAPHS:
 *		-Output Drivers (Thanks to the PLPlot Team):
 *			- On Display
 *			- PDF
 *			- Multiple Image Format
 *	RAW DATA:
 *		-Output Drivers (Thanks to Abdulilah :P ):
 *			- Matlab formatted .m File (including scripts n stuff)
 *			- Plain Text File .txt 
 *
 *
 *
*/
typedef struct {
	int method; //Which Method?
	//General (Euler and Euler Cromer)
	float g;	//Gravitational
	float l;	//Length of String
	float theta;//Initial Theta
	float omega;//Initial Omega
	float dt;	//Stepsize
	//Damping and Driving
	float df;	//Driving Force
	float dw;	//Driving Frequency
	float q; 	//Damping Effect. 
	float maxtime;
} SIMOPT;

typedef struct {
	//UsePl signifies if the user would like to see the graphs without having to export data
	//Thanks to PlPlot library. 
	int usePl;
	
	//Feel free to customized and add to this struct
	//for any simulation program you create.

	int thetaGraph;		//Plot Theta VS Time
	int omegaGraph;		//Plot Omega VS Time

	char filename[255];	//I have declared it to be a 255 char. 
	int matlab;		//0 no, not 0 yes;
} PRINTOPT;

int ReadSimOpt(SIMOPT *opt);
int ReadPrintOpt(PRINTOPT *opt);
int InitSimOpt(SIMOPT *opt);
int InitPrintOpt(PRINTOPT *opt);
int InitOPT(SIMOPT *sopt, PRINTOPT *popt);
int ParameterSweep(SIMOPT *s,PRINTOPT *p);
int SweeperSettings(float *start, float *end, float *step);
#endif
