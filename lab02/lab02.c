#include <stdio.h>

int main(){

	int n, i, j;
	double x;

	printf("Enter real number x, |x| < 1: ");
	scanf("%lf", &x);

	double temp = x * x;

	while(temp >= 1){
		printf("\nPlease enter valid x value: ");
		scanf("%lf", &x);
		temp = x * x;
		}

	printf("\nEnter n: ");
	scanf("%d", &n);
	
	
	int result1 = 0;
	int ttp = 1;
	for(i = 1; i <=n; i++){
		ttp *= -1;
		result1 += ttp;			
	}
	
	double xtopow = 1;
	double result2 = 0;
	for(j = 1; j <= i; j++){
		result2 += xtopow / j;
		xtopow += xtopow * x;
	}

	printf("\nAnswer is %f \n", result1 * result2);
	return 0;
}

