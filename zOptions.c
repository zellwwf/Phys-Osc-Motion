#include "zOptions.h"
#include "zSim.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ReadSimOpt(SIMOPT *opt) {
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
	float maxtime;	//Max Simulation Time
	int input;
	
	/*
		In Oscillatory Motion and Chaos
		We have the following inputs:
			- Initial THeta
			- Intial Omega
			- Length of string
			- Gravitational Acceleration 
	*/
	printf("\n----Simulation Parameters----\n");
	printf("\nMENU (choose one of the following commands)\n");
	printf("\n\t\t 1 - Adjust Method\tCurrent Method\t%d\n",opt->method);
	printf("\n\tFor All 3 Simulation:\n");
	printf("\n\t\t 2 - Adjust Gravity (m/s^2)\t\tCurrent Val %f",opt->g);
	printf("\n\t\t 3 - Adjust String Length (m)\t\tCurrent Val %f",opt->l);
	printf("\n\t\t 4 - Adjust Initial Theta (degrees)\tCurrent Val %f",opt->theta);
	printf("\n\t\t 5 - Adjust Initial Omega (deg/sec)\tCurrent Val %f",opt->omega);
	printf("\n\t\t 6 - Adjust Step size (s)\t\tCurrent Val %f",opt->dt);
	printf("\n\t\t 7 - Adjust Max Sim. Time\t\tCurrent Val %f",opt->maxtime);
	//Driving and Drag
	printf("\n\n\tFor For Driving and Damping Simulation Method:\n");
	printf("\n\t\t 8 - Adjust Driving Force (n)\t\tCurrent Val %f",opt->df);
	printf("\n\t\t 9 - Adjust Driving Frequency (hz)\tCurrent Val %f",opt->dw);
	printf("\n\t\t 10 - Adjust Damping Force (n)\t\tCurrent Val %f",opt->q);

	printf("\n\n\t 0 - <DONE>\n>>");
	scanf("%d",&input);

	switch(input) {
		case 0:
			return 0;
		case 1:
			printf("\n\t\t 1 - Simple Harmonic, Euler Method");
			printf("\n\t\t 2 - Simple Harmonic, Euler-Cromer Method");
			printf("\n\t\t 3 - With Driving and Damping, Euler-Cromer Method");
			printf("Enter Method (1,2,3) Value: ");
			scanf("%d",&method);
			opt->method = method;
			break;
		case 2:
			printf("Enter Gravity Value: ");
			scanf("%f",&g);
			opt->g = g;
			break;
		case 3:
			printf("Enter String Length Value: ");
			scanf("%f",&l);
			opt->l = l;
			break;
		case 4:
			printf("Enter Initial Theta Value: ");
			scanf("%f",&theta);
			opt->theta = theta;
			break;
		case 5:
			printf("Enter Initial Omega Value: ");
			scanf("%f",&omega);
			opt->omega = omega;
			break;
		case 6:
			printf("Enter DT Value: ");
			scanf("%f",&dt);
			opt->dt = dt;
			break;
		case 7:
			printf("Enter Maximum Simulation Time: ");
			scanf("%f",&maxtime);
			opt->maxtime = maxtime;
			break;
		case 8:
			printf("Enter Driving Force Value: ");
			scanf("%f",&df);
			opt->df = df;
			break;
		case 9:
			printf("Enter Driving Freq Value: ");
			scanf("%f",&dw);
			opt->dw = dw;
			break;
		case 10:
			printf("Enter Damping Force Value: ");
			scanf("%f",&q);
			opt->q = q;
			break;
		default:
			printf("Invalid Input!");
			break;
	}
	return 1;

}
int ReadPrintOpt(PRINTOPT *opt) {
	int input;

	int usePl;
	int thetaGraph;		
	int omegaGraph;

	//The result behind this def, i would like the user to input a filename
	//To save his data in, 
	char filename[255] = "Osc Motion and Chaos- Results"; //I have declared filename as char [255]

	int matlab;
	printf("\n----Print Options----\n");
	printf("\nMENU (choose one of the following commands)\n");
	printf("\n\t 1 - Display Graphs after Simulation\tCurrent Val\t%d",opt->usePl);
	printf("\n\t 2 - Enable Theta vs Time Graph\t\tCurrent Val\t%d",opt->thetaGraph);
	printf("\n\t 3 - Enable Omega vs Time Graph\t\tCurrent Val\t%d",opt->omegaGraph);
	printf("\n\t 4 - Save Data in Matlab Format\t\tCurrent Val\t%d",opt->matlab);
	printf("\n\t 5 - Filename for exported files\n\t\tCurrent Val\t%s",opt->filename);
	printf("\n\n\t 0 - <DONE>\n>>");
	scanf("%d",&input);

	switch(input) {
		case 0: 
			return 0;
		case 5:
			printf("Enter Filename: ");		
			scanf("%255s",filename);	//i've been told to use this, saw it on another question
			//opt->filename = filename;		//*In this part, opt is of type PRINTOPT
			strcpy(opt->filename,filename);
			//I have been told that the name of an array, is actually 
			//a pointer to the first element, so why does this part 
			//give me this error -- Operands of '=' have incompatible types 'char[255] and [char*]
			//although i've declared both as char[255]; 
			break;
		case 4:
			printf("Enable Matlab (0 no, else yes): ");
			scanf("%d",&matlab);
			opt->matlab = matlab;
			break;
		case 1:
			printf("Use this program to display plots (0 no, else yes): ");
			scanf("%d",&usePl);
			opt->usePl = usePl;
			break;
		case 2:
			printf("Record Data for Graph of Theta (0 no, else yes): ");
			scanf("%d",&thetaGraph);
			opt->thetaGraph = thetaGraph;
			break;
		case 3:
			printf("Record Data for Graph of Omega (0 no, else yes): ");
			scanf("%d",&omegaGraph);
			opt->omegaGraph = omegaGraph;
			break;
		default:
			printf("Invalid Input!");
			break;
	}
	return 1;
}
int InitSimOpt(SIMOPT *opt) {
	opt->g = 9.8;
	opt->l = 9.8;
	opt->theta = 7;
	opt->omega = 0;
	opt->dt = 0.04;
	opt->df = 1.2;
	opt->dw = 0.66666667;
	opt->q = 0.5;
	opt->method =3;
	opt->maxtime = 80;

	return 1;
}
int InitPrintOpt(PRINTOPT *opt) {
	char f[255] ="Osc Motion and Chaos - Results.txt";
	strcpy(opt->filename,f);
	opt->matlab = 1;
	opt->usePl = 1;
	opt->thetaGraph = 1;
	opt->omegaGraph = 1;
	return 1;
}
int InitOPT(SIMOPT *sopt, PRINTOPT *popt) {
	//Reason, Just so everything can be initialized by one funciton  in main
	if (InitSimOpt(sopt)) {
		if (InitPrintOpt(popt)) {
			return 1; //Success
		} else {
			return -1; //SimOpt Failed
		}
	} else {
		return -2;	  //PrintOpt Failed
	}

}
int ParameterSweep(SIMOPT *s,PRINTOPT *p) {
	//Use this to create parameter sweeps
	//The user has to select 3 values:
	//- Initial
	//- Final
	//increment
	int input;
	float i;
	float f;
	float inc;
	int num_iterations_total = 0;
	int num_iterations = 0;

	printf("\n----Parameter Sweeper----\n");
	printf("\nSweep Options, Select Which Variable you want to sweep in, this will override the value set in Sim. Options\n");
	printf("\n\t 1 - Driving Force");
	printf("\n\t 2 - Driving Frequency");
	printf("\n\t 3 - Damping Force");
	printf("\n\t 4 - Initial Theta");
	printf("\n\n\t 0 - <BACK>\n>>");
	scanf("%d",&input);
	char fn[255];
	
	switch(input) {
		case 0:
			return 0;
		case 1:
			printf("\n------------------Parameter Sweeper--------------------\n");
			printf("\nSweep on: Driving Force\n");
			//the end file name should be 255, concat the head, the number and the ext.
			char ff[245] = "Sweep on Driving Force - df =";
			strcpy(fn,ff);
			if (SweeperSettings(&i,&f,&inc)) {
				for (i;i<f+inc;i+=inc) {
					s->df = i;
					//fill in num with I

					//Concat
					sprintf(fn,"%s%f.txt",ff,i);
					strcpy(p->filename,fn);
					//send to Sim function	
					num_iterations = Simulate(*s,*p);
					num_iterations_total +=num_iterations;

					
				}
				printf("\nParameter Sweep Completed!\nIterations per sweep: %d\nIterations total: %d",num_iterations,num_iterations_total);
			}
			break;

		case 2:
			printf("\n------------------Parameter Sweeper--------------------\n");
			printf("\nSweep on: Driving Frequency\n");
			//the end file name should be 255, concat the head, the number and the ext.
		    strcpy(ff,"Sweep on Driving Frequency - dw = ");
			strcpy(fn,ff);
			if (SweeperSettings(&i,&f,&inc)) {
				for (i;i<f+inc;i+=inc) {
					s->dw = i;
					//fill in num with I

					//Concat
					sprintf(fn,"%s%f.txt",ff,i);
					strcpy(p->filename,fn);
					//send to Sim function	
					num_iterations = Simulate(*s,*p);
					num_iterations_total +=num_iterations;

					
				}
				printf("\nParameter Sweep Completed!\nIterations per sweep: %d\nIterations total: %d",num_iterations,num_iterations_total);
			}
			break;

		case 3:
			printf("\n------------------Parameter Sweeper--------------------\n");
			printf("\nSweep on: Damping Force\n");
			//the end file name should be 255, concat the head, the number and the ext.
			strcpy(ff,"Sweep on Damping Force - q = ");
			strcpy(fn,ff);
			if (SweeperSettings(&i,&f,&inc)) {
				for (i;i<f+inc;i+=inc) {
					s->q = i;
					//fill in num with I

					//Concat
					sprintf(fn,"%s%f.txt",ff,i);
					strcpy(p->filename,fn);
					//send to Sim function	
					num_iterations = Simulate(*s,*p);
					num_iterations_total +=num_iterations;

					
				}
				printf("\nParameter Sweep Completed!\nIterations per sweep: %d\nIterations total: %d",num_iterations,num_iterations_total);
			}
			break;

		case 4:
			printf("\n------------------Parameter Sweeper--------------------\n");
			printf("\nSweep on: Initial Theta\n");
			//the end file name should be 255, concat the head, the number and the ext.
			strcpy(ff,"Sweep on Initial Theta - theta_i = ");
			strcpy(fn,ff);
			if (SweeperSettings(&i,&f,&inc)) {
				for (i;i<f+inc;i+=inc) {
					s->theta = i;
					//fill in num with I

					//Concat
					sprintf(fn,"%s%f.txt",ff,i);
					strcpy(p->filename,fn);
					//send to Sim function	
					num_iterations = Simulate(*s,*p);
					num_iterations_total +=num_iterations;

					
				}
				printf("\nParameter Sweep Completed!\nIterations per sweep: %d\nIterations total: %d",num_iterations,num_iterations_total);
			}

			break;
		default:
			printf("\nERROR: Invalid Menu Selection");
			break;
	}
	return 1;
}
int SweeperSettings(float *start, float *end, float *step) {
	printf("\nEnter Starting Value:\n>>");
	scanf("%f",start);
	printf("\nEnter Ending Value:\n>>");
	scanf("%f",end);
	printf("\nEnter Step:\n>>");
	scanf("%f",step);
	int x = ((*end-*start)/ *step)+1;
	int cont;
	printf("\n\nThis will cause a total of %d iterations\n... Should we Start? (1 YES, 0 NO)\n>>",x);
	scanf("%d",&cont);
	if (cont)
		return 1;
	else 
		return 0;

}
