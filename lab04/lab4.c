#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void strwrk(char *input);
char *getstring();
void insertion_sort(char **words, int n);
void bubble_sort(char **words, int n);
char *letter_freq(char input[]);
void keyboard_input();
char **tokenize(char *in, int amount);
char *detokenize(char **in, int size, int n);
void file_input();
//int generate_random();

void strwrk(char *input){
	char ** w, * p;
	int * wl, l, i;
	w=malloc(strlen(input)/2*sizeof(char *));
	wl=malloc(strlen(input)/2*sizeof(int));
	for (i=0, p=input; *(p+=strspn(p, " \t")); p+=wl[i++]){
		w[i]=p;
		wl[i]=strcspn(p, " \t");
	}
	l=i;
	w=realloc(w, l*sizeof(char *));
	wl=realloc(wl, l*sizeof(int));
	for (i=0; i<l; i++)
		printf("'%.*s' - %d\n", wl[i], w[i], wl[i]);
	

	free(w);
	free(wl);
/*    int input_len = strlen(input);
    //Вычисление количества слов (кол-во пробелов + 1)
    int word_amount = 1, i;
    for(i = 0; input[i]; i++){
        word_amount += (input[i] == ' ');
    }

    //Предобработка строк для сортировки
    char *bubble_str = calloc(strlen(input)+1, sizeof(char));
    memcpy(bubble_str, input, input_len+1);
    char *insertion_str = calloc(strlen(input)+1, sizeof(char));
    memcpy(insertion_str, input, input_len+1);

    //Токенизация строки для сортировки пузырьком
    char **bubble_words = tokenize(bubble_str, word_amount);

    clock_t sort_time = clock(); //Начало таймера сортировки
    bubble_sort(bubble_words, word_amount);
    sort_time = clock() - sort_time;
    double bubble_time = (double) (sort_time / CLOCKS_PER_SEC);//Конец таймера сортировки

    //Собирается строка из отсортированных пузырьком слов
    char *bubble_out = detokenize(bubble_words, input_len, word_amount);
    free(bubble_str); //Освобождается строка для сортировки пузырьком

    //Токенизация строки для сортировки вставками
    char **insertion_words = tokenize(insertion_str, word_amount);

    sort_time = clock();     //Начало таймера сортировки
    insertion_sort(insertion_words, word_amount);
    double insertion_time = ((clock() - sort_time)/CLOCKS_PER_SEC); //Конец таймера сортировки

    //Собирается результат сортировки вставками
    char *insertion_out = detokenize(insertion_words, input_len, word_amount);
    free(insertion_str); //Освобождается строка для сортировки вставками

    char *freq = letter_freq(input); // Находится количество кажого символа в строке

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


void bubble_sort(char **words, int amount) {
    int i, j;
    char *temp;
    for (i = 0; i < amount - 1; i++) {
        for (j = amount - 1; j > i; j--) {
            if (strcmp(words[j - 1], words[j]) > 0) {
                temp = words[j - 1];
                words[j - 1] = words[j];
                words[j] = temp;
            }
        }
    }
}

void insertion_sort(char **words, int n){
    int i, j;
    char *temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(strcmp(words[i], words[j]) > 0){
                temp = words[j];
                words[j] = words[i];
                words[i] = temp;

            }
        }
    }
}

char *letter_freq(char *input){
    char *out = NULL, *workingstr = NULL, temp[120];
    int i, j, len = strlen(input), counter = 0, out_len = 0;
    workingstr = calloc(strlen(input), sizeof(char));
    memcpy(workingstr, input, len);
    for(i =0; i < len; i++){
        counter = 1;
        if(workingstr[i]) {
            for(j = i + 1; j < len; j++){
                if(workingstr[i] == workingstr[j]){
                    counter++;
                    workingstr[j] = '\0';
                }
            }
            sprintf(temp, "'%c' = %d\n", input[i], counter);
            int part_len = strlen(temp);
            out = realloc(out, part_len+out_len+1);
            memcpy(out+out_len, temp, part_len);
            out_len = out_len + part_len;
        }
    }
    out[out_len] = '\0';
    free(workingstr);
    return out;
}
//Во входной строке пробелы заменяются на \0 функция выводит массив указателей на начала слов
char **tokenize(char *in, int amount){
    int new_word, i, j;
    char **out = calloc(amount, sizeof(char *));
    for(j = 0, i = 0; in[i]; i++){
        if(in[i] == ' '){
            in[i] = '\0';
            new_word = 1;
        }
        else if(new_word){
            out[j++] = &in[i];
            new_word = 0;
        }
    }
    return out;
}

char *detokenize(char **in, int size, int n){
    char *out = calloc(size, sizeof(char));
    int i, len = 0;
    for(i = 0; i < n; i++){
        int part_len = strlen(in[i]);
        if(i != 0) {
            memcpy(out+len++, " ", 1);
        }
        memcpy(out + len, in[i], part_len);
        len += part_len;
    }
    out[len] = '\0';
    return out;
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

void keyboard_input(){
    char *input;
    input = getstring();
    strwrk(input);
    free(input);
}

void file_input(){
    char input[10000];
    char name[100];
    FILE *file;
    scanf("%s", name);
    while(!(file = fopen(name, "r"))){
        printf("Cannot open file!\n");
        scanf("%s", name);
    }
    fgets(input, 10000, file);
    strwrk(input);
}

int main(){
	printf("Starting...\n");
    int status = 1, menu;
    while (status){
        printf("Please enter a number 1 - 4\n1: Input string from keyboard\n2: Input from file\n3: Generate random string\n4: Quit\n");
        if(scanf("%d", &menu) != 1) {
			scanf("%*[^\n]");
            menu = 0;
        }
		scanf("%*c");
        switch (menu) {
            case 1:
                printf("-----Option one - keyboard input-----\nEnter a string to work with\n");
                keyboard_input();
                break;
            case 2:
                printf("-----Option two - file input-----\nEnter input file name\n");
                file_input();
                break;
            case 3:
                printf("-----Option three - random input-----\nEnter seed to generate a random string\n");
                //generate_random();
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
