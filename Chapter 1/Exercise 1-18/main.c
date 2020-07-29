#include <stdio.h>

#define MAXLINE		255		// Max input line length

int blankArray(char line[]);



int main(void){
	
	// end is used to mark when to stop looking for trailing whitespace
	int c, i = 0, j = 0, end = 0;
	char line[MAXLINE];
	
	while ((c = getchar()) != EOF){
		// when the enter key is pressed the program will strip the trailing spaces and tabs, then print the string
		if (c == '\n'){
			line[i] = c;
			for (j = i; ((j >= 0) && (end == 0)); --j){
				if ((line[j] == '\n') || (line[j] == ' ') || (line[j] == '\t')){
					line[j] = 0;
				}
				else{
					end = 1;
					// This adds the newline character that was destroyed back to the end of the new string
					line[j + 1] = '\n';
					// This will add a \0 after the newline to mark the end of the string
					line[j + 2] = '\0';
				}
			}
			// If the line wasn't blank, print it
			if ((j + 1) > 0){
				printf("%s", line);
			}
			
			// this cleans up the array and the variables for the next line
			i = 0;
			blankArray(line);
			end = 0;
		}
		else{
			// If the character isn't a space, tab, or newline, print it.
			// Also, if the next character is over the limit, it won't try to add it to the array.
			if (i < MAXLINE){
				line[i] = c;
				++i;
			}
		}
	}
	
	return 0;
}


// When fed an array, it will set each element to 0
int blankArray(char line[]){
	
	int i;
	
	for (i = 0; i < MAXLINE; i++){
		line[i] = 0;
	}
	
	return 0;
}

