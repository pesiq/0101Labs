#include "list.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int amount, len, i;
    clock_t time, total_time;
    const char charset[] = " abcdefghijklmnopqrstuvwxyz";


    printf("Please enter the amount of strings to be generated: \n");
    while (scanf("%d", &amount) != 1) {
        scanf("%*[^\n]");
        printf("Please enter a number!\n");
    }

    printf("Please enter the length of strings\n");
    while (scanf("%d", &len) != 1) {
        scanf("%*[^\n]");
        printf("Please enter a number!\n");
    }

    while(amount--){
        List *list = new_list();
        for(i = 0; i<len; i++){
            srand(clock());
            list_append(list, charset[rand() % strlen(charset)]);
        }

        printf("Working on string '");
        print_list(list);
        time = clock();
        remove_repeating(list);
        total_time += time;
        printf("'\nResult is '");
        print_list(list);
        printf("'\n");

        free_list(list);
    }

    printf("Avg time to work on one string is: %.30f", (double)(total_time / CLOCKS_PER_SEC) / amount);

    return 0;
}