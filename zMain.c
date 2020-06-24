#include "zOptions.H"
#include "zMain.H"
#include <stdlib.h>
#include <stdio.h>

int SetDesc(ProgDetails *p,char *name, char *desc) {
	p->name = name;
	p->desc = desc;
	return 1;
}
void PrintWelcome(ProgDetails *p) {
	printf("%s\t\t\tAbdulilah Azzazi\n\n",p->name,p->desc);
}
int Menu() {
	//Here please adjust for each individual program
	//Returns Menu Entry Hit!
	int input;

	printf("\n------------------------Main Menu------------------------\n");
	printf("\n\t\t 1 - Start Simulations");
	printf("\n\t\t 2 - View Simulation Parameters");
	printf("\n\t\t 3 - View Print (Output) Options");
	printf("\n\t\t 4 - Create Parameter Sweep");
	printf("\n\n\t\t 0 - <EXIT>\n>>");
	scanf("%d",&input);
	return input;
	
}
