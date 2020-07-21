#include <stdio.h>

// Copies input to output, but replaces multiple spaces with a single space

int c, x = 0;

int main(void){
	
	while ((c = getchar()) != EOF){
		// If the current char is a space
		if (c == ' '){
			// Check to see if the last char is a space
			if (x != ' '){
				// If it wasn't, then you can print a space
				putchar(' ');
			}
			// Sets the current char to x, so we can check to see if it was a space next time around
			x = c;
		}
		else{
			// If it wasn't a space, send it to output
			putchar(c);
			// Sets the current char to x, so we know it wasn't a space next time around
			x = c;
		}
	}
	
return 0;
}


