#include <stdio.h>

int main(int argc, char *argv[]) {
	float fahr, celsius;
	int step, lower, upper;

	celsius = lower;
	upper = 300;

	printf("%4s %6s \n", "cel", "fahr");
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%4.0f %6.1f \n", celsius, fahr); 
		
		celsius = celsius + 20;
	}
}
