#include <stdio.h>


int main(void){


	int c;
	
	// On *nix you can do "Ctrl + D" to send EOF to the terminal emulator.
	c = (getchar() != EOF);
	
	if (c == 1){
		printf("\"getchar() != EOF\" is 1\n");
	}
	else if (c == 0){
		printf("\"getchar() != EOF\" is 0\n");
	}
	else{
		printf("Something probably went wrong lol\n");	
	}
	return 0;
}
