#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *new_list(){
    return (List*) calloc(1, sizeof(List));
}

void print_list(const List *list){
    Item *temp = list->head;
    while(temp){
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(List *list){
    Item *ptr = list->head, *ptr_prev;
    while(ptr){
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
}

void list_append(List *list, char data){
    Item *ptr = malloc(sizeof(Item));

    ptr->data = data;
    ptr->next = NULL;

    if(!list->head){
        list->head = ptr;
        list->tail = ptr;
    }
    else{
        list->tail->next = ptr;
        list->tail = ptr;
    }
}

void list_remove_from(List *list, Item *prev, char data){
    Item *curr = prev->next;
    while (curr && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    if(!curr) return;
    if(curr == list->tail) list->tail = prev;
    if(curr) prev->next = curr->next;
    free(curr);
}

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
