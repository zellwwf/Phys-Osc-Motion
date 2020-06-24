#define M_PI 3.14159265358979323846
#include "zSim.H"
#include "zDA.h"
#include "zOptions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int Simulate(SIMOPT so,PRINTOPT po) {
	printf("\nSimulation Starting...\nCreating Containers...");
	//Create Data Objects
		//vectors
	DATA Theta,Omega,T;
	DATA *pTheta = &Theta;
	DATA *pOmega = &Omega;
	DATA *pT = &T;

		//Initial Values
	int method = so.method;
	float g = so.g;
	float l = so.l;
	float itheta = so.theta;
	float iomega = so.omega;
	float dt = so.dt;
	float df = so.df;
	float dw = so.dw;
	float q = so.q;
	float maxtime = so.maxtime;

	float i = 0; //Simulation Counter
	int k=0;	 //Counter to Count array size;
	int kmax = 0;
	float th,thi,om,omi,t,ti; //Simulation variables

	int gt,go,pl,mat;
	printf("\nDone!\nInitializing Containers...");

	//Initialize Containers
	InitializeArray(pTheta,"Theta");
	InitializeArray(pOmega,"Omega");
	InitializeArray(pT,"Time");

	
	gt = po.thetaGraph;
	go = po.omegaGraph;
	pl = po.usePl;		//For when i learn PL plot
	mat = po.matlab;
	//Minor Calulations
			//None required

	//Set Initial Value
	printf("\nDone!\nSetting Initial Values...");
	AddToArray(pTheta,itheta);
	AddToArray(pOmega,iomega);
	AddToArray(pT,0);
	th = pTheta->the_array[0];
	om = pOmega->the_array[0];
	t = pT->the_array[0];

	printf("\nDone!\nSTARTING SIMULATION...");
	//Simulation Phase
	switch (method) {
		case 1: //Euler Method
			for(i = 0;i<maxtime;i+=dt) {
				th = pTheta->the_array[k];
				om = pOmega->the_array[k];
				t = pT->the_array[k];

				//Omega Vector
				omi = om - (g/l)*th*dt;
				AddToArray(pOmega, omi);
				//Theta Vector
				thi = th + om*dt;
				AddToArray(pTheta,thi);
				//Time Vector
				ti = t+dt;
				AddToArray(pT,ti);

				//is there another condition for exit? NO
				if (k%10==0)
					printf("\n.");
				k++;
		
			}
			kmax = k;
			break;

		case 2: //Euler Cromer Method
			for(i = 0;i<maxtime;i+=dt) {
				th = pTheta->the_array[k];
				om = pOmega->the_array[k];
				t = pT->the_array[k];

				//Omega Vector
				omi = om - (g/l)*th*dt;
				AddToArray(pOmega, omi);
				//Theta Vector
				thi = th + omi*dt;
				AddToArray(pTheta,thi);
				//Time Vector
				ti = t+dt;
				AddToArray(pT,ti);

				//is there another condition for exit? NO
				if (k%10==0)
					printf("\n.");
				k++;
		
			}
			kmax = k;
			break;

		case 3: //Realistic Model
			for(i = 0;i<maxtime;i+=dt) {
				th = pTheta->the_array[k];
				om = pOmega->the_array[k];
				t = pT->the_array[k];

				//Omega Vector
				omi = om - (g/l)*sin(th)*dt - q*om*dt + df*sin(dw*t)*dt;
				AddToArray(pOmega, omi);
				//Theta Vector
				thi = th + omi*dt;
					//adjustments copied from book
				//if (thi>180)
				//	thi-360;
				//if (thi<-180)
				//	thi+360;
				AddToArray(pTheta,thi);
				//Time Vector
				ti = t+dt;
				AddToArray(pT,ti);

				//is there another condition for exit? NO
				if (k%10==0)
					printf("\n.");
				k++;
		
			}
			kmax = k;
			break;
		default:
			printf("\nERROR: Invalid Method Selected -- Cancelling Simulation!");
			return -1;
			break;
	}

	printf("\nSIMULATION COMPLETED!\nNumber of Iterations:%d\n",kmax);

	//Now the Printing Section -- THIS should be Seperate from simulate, but do it later

	//Open File Stream
	FILE * pFile;
  	pFile = fopen (po.filename,"w");


	//Write File Heads
	fprintf(pFile,"%%\t\tSimulation Results and Data\n");
	fprintf(pFile,"%%Just Copy the file in Matlab");
	fprintf(pFile,"\nmethod = %d;\ntheta_i = %f;\nomega_i =%f;\ng = %f;\nl= %f;\ndf = %f;\ndw = %f;\nq = %f\nmaxtime = %f;\ndt = %f;",method,itheta,iomega,g,l,df,dw,q,maxtime,dt);
	//Printing Phase


		//Print Theta Vec
	if (gt) {
		if (mat) {
			fprintf(pFile,"\nTheta = [\n");
			for (k = 0;k<kmax+1;k++) {
				fprintf(pFile,"%f\n",pTheta->the_array[k]);
			}
			fprintf(pFile,"\n];");
		}
		if (pl) {

		}

	}

		//Print omega Vec
	if (go) {
		if (mat) {
			fprintf(pFile,"\nOmega = [\n");
			for (k = 0;k<kmax+1;k++) {
				fprintf(pFile,"%f\n",pOmega->the_array[k]);
			}
			fprintf(pFile,"\n];");
		}
		if (pl) {

		}
	}

	if (go || gt) {	//Print Time Vec
		if (mat) {
			fprintf(pFile,"\nT = [\n");
			for (k = 0;k<kmax+1;k++) {
				fprintf(pFile,"%f\n",pT->the_array[k]);
			}
			fprintf(pFile,"\n];");
			
			fprintf(pFile,"\nh_ = figure(1);");
			fprintf(pFile,"\nfigure(1);");
			fprintf(pFile,"\nplot(T,Theta);");
			fprintf(pFile,"\ntitle('%s')",po.filename);
			fprintf(pFile,"\nxlabel('Time (s)');");
			fprintf(pFile,"\nylabel('Theta (deg)');");

			
		}
		if (pl) {

		}
	}

	printf("\nResults Printed!\n");
	//Close Streams and Free Memory

	fclose(pFile);
	free(pTheta->the_array);
	free(pOmega->the_array);
	free(pT->the_array);
	return kmax;
}
