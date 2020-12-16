#include <stdio.h>
#include "list.h"

void remove_repeating(List *list){
    Item *ptr = list->head;
    while(ptr){
        char val = ptr->data;
        Item *temp = ptr;
        while(temp) {
            list_remove_from(list, ptr,val);
            temp = temp->next;
        }
        ptr = ptr->next;
    }
}

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
