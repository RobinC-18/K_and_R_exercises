#include <stdio.h>

double fahr_to_cels(int fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}

int main(int argc, char *argv[]) {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	printf("%4s %6s \n", "fahr", "cel");
	while (fahr <= upper) {
		celsius = fahr_to_cels(fahr);
		printf("%4.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;

	}
}
