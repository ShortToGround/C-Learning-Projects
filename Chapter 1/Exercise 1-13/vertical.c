#include <stdio.h>

#define IN					1
#define OUT					0
#define MAX_WORD_LENGTH		49 // I chose because the largest accepted english word is 45 characters so I just rounded to 50
							   // Including 0 of course!

// I just reused the code from my last exercise and changed it to my needs
// This is the vertical version, which is more difficult

// With the code functionally complete I went ahead and added a section to keep track of the largest word recorded
// That way the histogram resolution only has to be as large as the largest word

int main(void){

	int i, j, word, c = 0, length = 0, largestWord = 0, maxCount = 0;
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
				if ((largestWord) < length){
					largestWord = length;
				}
				length = 0;
			}
		}
	}
	
	// This will search the entire array, limited by largestWord and return the 
	// number with the highest count, which is my y value resolution
	for (i = 0; i <= largestWord; ++i){
		if (wlength[i] > maxCount){
			maxCount = wlength[i];
		}
	}
	
	//printf("x axis limit is: %d\n", largestWord);
	//printf("y axis limit is: %d\n", maxCount);
	
	
	// y axis loop
	for (i = 0; i < maxCount; ++i){
		// x axis loop
		if ((maxCount - i) < 10){
			printf(" %d", (maxCount - i));				
		}
		else{
			printf("%d", (maxCount - i));
		}

		for (j = 0; j < largestWord; ++j){
			if (wlength[j] >= (maxCount - i)){
				printf(" * ");
			}
			else{
				printf("   ");
			}
		}
		printf("\n");	
	}
	
	for (i = 0; i < largestWord; ++i){
		if (i == 0){
			printf("  ");
		}
		// This will determine when to add an extra space to the x axis legend
		// in order to keep everything even
		if (i > 9){
			printf("%d ", (i + 1));
		}
		else{
			printf(" %d ", (i + 1));
		}
	}
	printf("\n");
	return 0;
}
