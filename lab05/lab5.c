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
