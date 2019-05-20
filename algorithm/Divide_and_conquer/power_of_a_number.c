#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiply(int, int);

int main(){
	int num = 2;
	int power = 10;
	printf("%d\n", multiply(num, power));
	return 0;
}

int multiply(int number, int power){
	if(number == 0){
		return 0;
	}
	if(power == 0){
		return 1;
	}
	if(power % 2 == 0){
		return multiply(number, power / 2) * multiply(number, power / 2);
	}
	else{
		return multiply(number, (power - 1) / 2) * multiply(number, (power - 1) / 2) * number;
	}
}
