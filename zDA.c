#include "zDA.h"
#include <stdlib.h>
#include <stdio.h>

int AddToArray (DATA *item, float val)
{
        if(item->num_elements == item->num_allocated) // Are more refs required?
        { 
                // Feel free to change the initial number of refs
                // and the rate at which refs are allocated.
                if (item->num_allocated == 0)
                        item->num_allocated = 100; // Start off with these refs
                else
                        item->num_allocated *= 2; // Double the number 
                                                    // of refs allocated

                // Make the reallocation transactional 
                // by using a temporary variable first
                DATA *_tmp = realloc(item->the_array, (item->num_allocated * sizeof(float)));

                // If the reallocation didn't go so well,
                // inform the user and bail out
                if (!_tmp)
                {
                        printf("ERROR: Couldn't realloc memory!\n");
                        return(-1);
                }

                // Things are looking good so far
                item->the_array = (float*)_tmp;
        }
		
       		item->the_array[item->num_elements] = val;
        	item->num_elements++;

        return item->num_elements;
}
int InitializeArray (DATA *item, char *n) {
	item->name = n;
	item->num_allocated = 0;
	item->num_elements = 0;
	item->the_array = NULL;
	if (!item->the_array) {
	return -1;
	}
	return 0;
}
