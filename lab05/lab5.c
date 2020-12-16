#include <stdio.h>
#include "list.h"

int main(){

    char t;

	do{
		
		List *string = new_list();

		printf("Enter a string to work with\n");
    	do{
			t = getchar();
        	list_append(string, t);
    	}while(t != '\n' && t != EOF);

    	string->tail->data = '\0';

    	remove_repeating(string);

    	print_list(string);
    	free_list(string);
	
	}while(t != EOF);

    return 0;
}
