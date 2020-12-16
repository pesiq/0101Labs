#include "list.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int amount, len, i, work;
    const char charset[] = " abcdefghijklmnopqrstuvwxyz";


    printf("Please enter the amount of strings to be generated: \n");
    while (scanf("%d", &amount) != 1) {
        scanf("%*[^\n]");
        printf("Please enter a number!\n");
    }
    work = amount;

    printf("Please enter the length of strings\n");
    while (scanf("%d", &len) != 1) {
        scanf("%*[^\n]");
        printf("Please enter a number!\n");
    }

    double total_time = 0;
    while(work--){
        List *list = new_list();
        for(i = 0; i<len; i++){
            list_append(list, charset[(rand() + i) % strlen(charset)]);
        }
        list_append(list, '\0');

        printf("Working on string:\n");
        print_list(list);
        clock_t t = clock();
        remove_repeating(list);
        t = clock() - t;
        double time = (double) t / CLOCKS_PER_SEC;
        total_time += time;
        printf("Result is:\n");
        print_list(list);

        free_list(list);
    }

    printf("Avg time to work on one string is: %.30f", total_time / amount);

    return 0;
}