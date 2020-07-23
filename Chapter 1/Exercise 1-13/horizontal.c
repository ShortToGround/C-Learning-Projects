#include <stdio.h>

#define IN					1
#define OUT					0
#define MAX_WORD_LENGTH		49 // I chose because the largest accepted english word is 45 characters so I just rounded to 50
							   // Including 0 of course!

// I just reused the code from my last exercise and changed it to my needs
// This is the horizonal version, which is easier

// With the code functionally complete I went ahead and added a section to keep track of the largest word recorded
// That way the histogram resolution only has to be as large as the largest word

int main(void){
	
	int i, j, word, c = 0, length = 0, largest = 0;
	int wlength[50];
	
	for (i = 0; i <= MAX_WORD_LENGTH; ++i){
		wlength[i] = 0;	
	}
	
	while ((c = getchar()) != EOF){
		// If c isn't a space, then it has to be a non-space character
		if ((c != ' ') && (c != '\n')){
			// this means we are currently in a word
			word = IN;
			++length;
		}
		else{
			// If it IS a space, and we're already in a word then this is the end of said word
			if (word == IN){
				// This will reset the word back to OUT since we are no longer in a word
				word = OUT;
				
				// If the length is greater than our max size then don't try to increment the array
				// This was a lazy fix, I could have done something more useful like make it increment a 
				// 		"error" counter or something
				if (length < (MAX_WORD_LENGTH + 1)){
					// Increment the word length count counter
					++wlength[length - 1];
				}
				if ((largest) < length){
					largest = length;
				}
				length = 0;
			}
		}
	}
	for (i = 0; i <= largest - 1; ++i){
		printf("%d: ", (i + 1));
		for (j = 0; j < wlength[i]; ++j){
			printf("*");	
		}
		printf("\n");
	}
	return 0;
}
