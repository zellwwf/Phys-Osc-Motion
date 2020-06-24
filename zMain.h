#ifndef ZMAIN_H
#define	ZMAIN_H
//Main h file that i will be using across my work this semester
typedef struct {
	char *name;
	char *desc;
} ProgDetails;

void PrintWelcome(ProgDetails *p);
int SetDesc(ProgDetails *p,char *name, char *desc);
int  Menu();


#endif
