#include <stdio.h>
#include <string.h>

void strwork(char in[], char out[]){
	
	int i, j, k;

	strcpy(out, "");

	for(i = 0; i < strlen(in); ++i){
		if (in[i] == '.')
			break;
	}

	for (j = 0; j < strlen(in); ++j){
		if (in[j] == ';')
			k = j;
	}
	++k;
	strncpy(out, in+i, k-i);
}


int main(){

 char stri[] = "q;wer	.0	ty.;ui.o	asd 	 dfg;dfg	kj df";
 char stro[strlen(stri)];
	
	strwork(stri, stro);

 printf("\"%s\"\n", stro);

}
