#include <stdio.h>

#define IN		1
#define OUT		0


int word, c = 0;

int main(void){
	
	while ((c = getchar()) != EOF){
		// If c isn't a space, then it has to be a non-space character
		if (c != ' '){
			putchar(c);
			// this means we are currently in a word
			word = IN;
		}
		else{
			// If it IS a space, and we're already in a word then this is the end of said word
			if (word == IN){
				// instead of outputting the space we will output a new line
				putchar('\n');
				// This will reset the word back to OUT since we are no longer in a word
				word = OUT;
			}
		}
	}

return 0;
}



