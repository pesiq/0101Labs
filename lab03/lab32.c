//Дана строка, содержащая слова, раздеоенные одним или несколькими разделительными символами, в начале и в конце строки
// так же могут находиться разделительные символы. Сформировать новую строк каждое четное слово по алфавиту 
//
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MLEN 500

void strwrk (char in[], char out[]){
	int i,k,l,j;
	char * w[MLEN];
	int wl[MLEN];
	
	strcpy(out, "");
	j = 0;
	for(l = 0, i = 0; in[i+=strspn(in+i, " \t")]!='\0'; i+=k, l++){
		k=strcspn(in+i," \t");
		if(l % 2 == 1){
			w[j] = in+i;
			wl[j]= k;
			j++;
		}
	}
		for(i = 0; i < j-1; i++){
			for(l = 0; l < j-i-1; l++){
				k = wl[l];
				if(wl[l] > wl[l+1]) k = wl[l+1];
				if(strncmp(w[l],w[l+1], k)>0){
				
				char* tc = w[l];
				w[l] = w[l+1];
				w[l+1] = tc;

				int ti = wl[l];
				wl[l] = wl[l+1];
				wl[l+1] = ti;
				}
			}
		}
	
	for(i = 0; i < j; ++i){
		if(i!=0) strcat(out," ");
		strncat(out, w[i], wl[i]);
		}

}

char *getstring(){

char buffer[121] = {0};
char *res = NULL;
int len = 0;
int n = 0;

	do{
		n = scanf("%120[^\n]", buffer);
		if(n < 0){
			if(!res){
				return NULL;
			}
		} else if ( n > 0){
		int part_len = strlen(buffer);
		int str_len = len + part_len;
		res = realloc(res, str_len+1);
		memcpy(res+len, buffer, part_len);
		len = str_len;
		} else {
			scanf("%*c");
			}

	}while (n > 0);

	if(len > 0){
	res[len] = '\0';
	} else {
	res = calloc(1, sizeof(char));
	}
	return res;
}


int main(){

char *words = NULL;
do{
words = getstring();
if(words){
	pritnf("%s\n", words);
	free(words);
	}
}while(words);

char out[MLEN]; 

printf("%s", words);

strwrk(words, out);
double time = clock();
printf("\"%s\" \n", out);
printf("Total time: %.81f seconds\n", time/CLOCKS_PER_SEC);

return 0;

}
