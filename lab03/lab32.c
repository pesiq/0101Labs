//Дана строка, содержащая слова, раздеоенные одним или несколькими разделительными символами, в начале и в конце строки
// так же могут находиться разделительные символы. Сформировать новую строк каждое четное слово по алфавиту 
//
//

#include <stdio.h>
#include <string.h>
#define MLEN 200

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

		for(i = 0; i < j; ++i){
			for(l = 0; l < i; ++l){
				k = wl[l];
				if(wl[l] > wl[l+1]) k = wl[l+1];
				printf("%d %d",i,l);
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
				//if(l!=0) strcat(out," ");
		//strncat(out, in+i, k);
	}
	for(i = 0; i < j; ++i){
		if(i!=0) strcat(out," ");
		strncat(out, w[i], wl[i]);
		}
}

int main(){

char words[] = {"		aa  aab 	asdfl ksldkfq 	poas poar nae werl asdop	 asme pikw cxcv asdiw dfvn		 x lqweo zxcsd pojret  	 	sdf olaira vsdip newrk aslc	 		"};
char out[MLEN]; 

strwrk(words, out);

printf("\"%s\" \n", out); 

return 0;

}
