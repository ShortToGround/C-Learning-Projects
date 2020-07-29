#include <stdio.h>

#define BUFFERSIZE		255		// Max input buffer length

// Thanks for the advice caze and wroathe!

int main(void){
	
	int c, i = 0, j = 0, charCheck = 0;
	char buffer[BUFFERSIZE];
	
	while ((c = getchar()) != EOF){
		if (c == '\n'){
			printf("\n%d tabs/spaces removed from the end of this line", i);
			charCheck = 0;
			i = 0;
			putchar(c);
		}
		else if ((c == ' ') || (c == '\t')){
			// This will simply ignore additions to the buffer if its full
			if (i < BUFFERSIZE){
				buffer[i] = c;
				++i;
			}
			charCheck = 1;
		}
		else{
			if (charCheck == 1){
				// If a non-whitespace char was encountered after a whitespace char
				//	this will dump the whitespace buffer and then write the new char
				for (j = 0; j < i; ++j){
					putchar(buffer[j]);
				}
				putchar(c);
				
				// State reset for next whitespace check
				charCheck = 0;
				i = 0;
			}
			else{
				putchar(c);
			}
		}
	}
	
	return 0;
}
