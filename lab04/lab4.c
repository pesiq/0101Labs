#include <stdio.h>

int main(){
	printf("Starting...");
	while(1){
		int menu;
		if (scanf("%d", &menu) != 1 || menu != 1 || menu != 2 || menu != 3 || menu !=4)
			printf("Please enter a number 1, 2, 3, or 4");
		else{
			printf("Ery noice");
			break;
		}
	}
	printf("Exiting...");
	return 0;
}
