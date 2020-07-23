#include <stdio.h>

float convert(float fahr){
	float celsius;
	
	celsius = (5.0/9.0) * (fahr-32.0);
	return celsius;
}

int main(void){
	
	float fahr;
	float lower, upper, step;
	
	lower = 0;		// lower limit of temperature scale
	upper = 300;	// upper limit
	step = 20;		// step size

	fahr = lower;
	
	printf("Fahr | Cels\n_____|_____\n");
	
	while (fahr <= upper){
		printf("%3.0f %6.1f\n", fahr, convert(fahr));
		fahr = fahr + step;
	}
	
return 0;
}
