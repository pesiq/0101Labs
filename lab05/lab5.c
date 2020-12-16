#include <stdio.h>
#include "list.h"

int main(){

    List *string = new_list();
    int i;

    do{
        list_append(string, getchar());
    }while(string->tail->data != '\n' && string->tail->data != EOF);

    string->tail->data = '\0';

    remove_repeating(string);

    print_list(string);
    free_list(string);

    return 0;
}
