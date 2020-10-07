#include <stdio.h>
#include <math.h>

int findNearestComplete(int n){
	if(n < 15 ) {
		return 6;
	}
	if(n < 249){
		return 28;
	}
	if(n < 4065) {
		return 8128;
	}
	else{
		return 33550336;
	}
}

int main(){

	int n;
	int sum = 0;

	printf("Please enter a number\n");
	scanf("%d", &n);
	if(n == 0){
		printf("The number is 0!\n");
		return 0;
	}

	int i;
	for(i = 1; i < n/2; i++){
		if(n % i == 0) {
			sum += i;
			sum += n/i;
		}
	}

	if(sum/2 == n){
		printf("The number %d is a complete number\n", n);
	}
	else{
		printf("The sum is %d => %d is not a complete number.\nClosest complete number is %d\n", sum/2, n, findNearestComplete(n));
	}

return 0;
}
