#ifndef D_ARRAY_H
#define	D_ARRAY_H

typedef struct {
	char 	*name;	//Hold the name of the data, ie, Time vector, ... etc 
	float    *the_array;
	int     num_elements; // Keeps track of the number of elements used
	int     num_allocated; // This is essentially how large the array is
} DATA;

int AddToArray (DATA *item, float val);
int InitializeArray (DATA *item, char *n);
#endif 
