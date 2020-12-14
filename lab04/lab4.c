#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void strwrk(char *input, int type);

char *getstring();

void insertion_sort(char **words, int *word_lengths, int amount);

void bubble_sort(char **words, int *word_lengths, int amount);

char *letter_freq(char input[]);

void keyboard_input();

void file_input();

void random_input();

char *generate_random();

void strwrk(char *input, int type) {
    char **words, *p;
    int *wl, l, i, len = strlen(input), ln = 0;
    words = malloc(len / 2 * sizeof(char *));
    wl = malloc(len / 2 * sizeof(int));
    for (i = 0, p = input; *(p += strspn(p, " \t")); p += wl[i++]) {
        words[i] = p;
        wl[i] = strcspn(p, " \t");
    }
    l = i;
    words = realloc(words, l * sizeof(char *));
    wl = realloc(wl, l * sizeof(int));

    double time;
    clock_t t;
    switch (type) {
        case 1:
            t = clock();
            bubble_sort(words, wl, l);
            time = (double) (clock() - t) / CLOCKS_PER_SEC;
            break;
        case 2:
            t = clock();
            insertion_sort(words, wl, l);
            time = (double) (clock() - t) / CLOCKS_PER_SEC;
            break;
    }

    char *output = calloc(len, sizeof(char));
    char *freq = letter_freq(input);
    for (i = 0; i < l; i++) {
        memcpy(output, words[i], wl[i]);
        ln += wl[i];
    }
    output[ln] = '\0';
    printf("Input string was '%s'\nSorted string is '%s'\nTime was: %.30f\nLetter frequency: %s\n", input, output, time,
           freq);

    free(words);
    free(wl);
    free(output);
    free(freq);
/*
    //Вывод результатов
    printf("Input string was:\n\"%s\"\nResult of bubble sort is:\n\"%s\"\nWith time of: %.50f\nResult of insertion sort is:\n\"%s\"\nWith time of: %.50f\n", input, bubble_out, bubble_time, insertion_out, insertion_time);
    printf("Frequency of each character used\n");
    printf("%s\n", freq);

    printf("Would you like to save the current state to a file? (yes/no) ");
    char *prompt = NULL;
    do{
        fflush(stdin);
        prompt = getstring();
        if (!strcmp(prompt, "yes")) {
            //write to file
            FILE *file;
            file = fopen("./output.txt", "w");
            fprintf(file,"Input string was:\n\"%s\"\nResult of bubble sort is:\n\"%s\"\nWith time of: %.50f\nResult of insertion sort is:\n\"%s\"\nWith time of: %.50f\n", input, bubble_out, bubble_time, insertion_out, insertion_time);
            fprintf(file,"Frequency of each character used\n%s", freq);
            fclose(file);
            printf("Saved to file\n");
            prompt = "no";
        }else {
            printf("Please enter yes or no\n");
        }
    }while(strcmp(prompt, "no"));
    printf("*****----------*****\n");
    free(freq), free(bubble_out), free(insertion_out);*/
}


void bubble_sort(char **words, int *word_lengths, int amount) {
    int i, j, t;
    char *temp;
    for (i = 0; i < amount - 1; i++) {
        for (j = amount - 1; j > i; j--) {
            if (strcmp(words[j - 1], words[j]) > 0) {
                temp = words[j - 1];
                words[j - 1] = words[j];
                words[j] = temp;

                t = word_lengths[j - 1];
                word_lengths[j - 1] = word_lengths[j];
                word_lengths[j] = t;
            }
        }
    }
}

void insertion_sort(char **words, int *word_lengths, int amount) {
    int i, j, t;
    char *temp;
    for (i = 0; i < amount - 1; i++) {
        for (j = i + 1; j < amount; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                temp = words[j];
                words[j] = words[i];
                words[i] = temp;

                t = word_lengths[j];
                word_lengths[j] = word_lengths[i];
                word_lengths[i] = t;
            }
        }
    }
}

char *letter_freq(char *input) {
    char *out = NULL, *workingstr = NULL, temp[120];
    int i, j, len = strlen(input), counter = 0, out_len = 0;
    workingstr = calloc(strlen(input), sizeof(char));
    memcpy(workingstr, input, len);
    for (i = 0; i < len; i++) {
        counter = 1;
        if (workingstr[i]) {
            for (j = i + 1; j < len; j++) {
                if (workingstr[i] == workingstr[j]) {
                    counter++;
                    workingstr[j] = '\0';
                }
            }
            sprintf(temp, "'%c' = %d", input[i], counter);
            int part_len = strlen(temp);
            out = realloc(out, part_len + out_len + 1);
            memcpy(out + out_len, temp, part_len);
            out_len = out_len + part_len;
        }
    }
    out[out_len] = '\0';
    free(workingstr);
    return out;
}

char *generate_random() {

    const char charset[] = "    abcdef ghijklmnopqrstuv wxyz ";
    int len = rand() % 50 + 20;
    char *dest = calloc(len + 1, sizeof(char));

    int i;
    for (i = 0; i < len; i++) {
        dest[i] = charset[rand() % strlen(charset)];
    }
    dest[len] = '\0';
    return dest;
}

char *getstring() {

    char buffer[121] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%120[^\n]", buffer);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int part_len = strlen(buffer);
            int str_len = len + part_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buffer, part_len);
            len = str_len;
        } else {
            scanf("%*c");
        }

    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

void keyboard_input() {

    int amount, type, i;
    char **strings;

    printf("Enter an amount of strings\n");
    while (scanf("%d", &amount) != 1) {
        scanf("%*[^\n]");
    }
    strings = malloc(amount * sizeof(char *));
    scanf("%*c");
    printf("Enter %d strings to work with\n", amount);
    for (i = 0; i < amount; i++) {
        strings[i] = getstring();
    }
    printf("Choose which sorting algorithm to use. Type 1 or 2\n 1. Bubble sort\n 2. Insertion sort\n");
    do {
        if (scanf("%d", &type) != 1) {
            scanf("%*[^\n]");
        }
    } while (type != 1 && type != 2);
    scanf("%*c");
    for (i = 0; i < amount; i++) {
        strwrk(strings[i], type);
        free(strings[i]);
    }
    free(strings);
}

void file_input() {
    char input[10000], name[100];
    int type = 1;
    FILE *file;
    scanf("%s", name);
    while (!(file = fopen(name, "r"))) {
        printf("Cannot open file!\n");
        scanf("%s", name);
    }
    fgets(input, 10000, file);
    strwrk(input, type);
}

void random_input() {

}

int main() {
    printf("Starting...\n");
    int status = 1, menu;
    while (status) {
        printf("Please enter a number 1 - 4\n1: Input string from keyboard\n2: Input from file\n3: Generate random string\n4: Quit\n");
        if (scanf("%d", &menu) != 1) {
            scanf("%*[^\n]");
            menu = 0;
        }
        scanf("%*c");
        switch (menu) {
            case 1:
                printf("-----Option one - keyboard input-----\n");
                keyboard_input();
                break;
            case 2:
                printf("-----Option two - file input-----\nEnter input file name\n");
                file_input();
                break;
            case 3:
                printf("-----Option three - random input-----\nEnter seed to generate a random string\n");
                generate_random();
                break;
            case 4:
                status = 0;
                break;
            default:
                printf("Illegal input!\n");
                break;
        }
    }
    printf("Exiting...\n");
    return 0;
}
