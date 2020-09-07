#include <stdio.h>

#define	MAXLINE		255
#define FOLDCOL 	25	// including 0

// Checks single char to see if it is a space, tab, or newline
int isBlank(int c);

int main(void){
	
	int i = 0;
	int c;
	char line[MAXLINE];
	int currentColumn = 0;
	int foldPoint = 0;
	int inWord = 0;
	int newLineCount = 0;
	
	while ((c = getchar()) != EOF){
		if (c == '\n'){
			for (i = 0; line[i] != '\0'; ++i){
				
				// See if we are in a word or not, useful for tracking the first white space char
				if ((!inWord) && (!isBlank(line[i]))){
					inWord = 1;
				}
				// The first whitespace found after a word will be marked to convert to \n for the fold
				else if ((inWord) && (isBlank(line[i]))){
					inWord = 0;
					foldPoint = i;
				}
				
				if (currentColumn == (FOLDCOL - 1)){
					if (foldPoint != 0){
						line[foldPoint] = '\n';
						i = (foldPoint);
						currentColumn = 0;
						foldPoint = 0;
					}
					else{
						currentColumn = 0;
						foldPoint = 0;
					}
				}
				else{
					++currentColumn;
				}
			}
				
			currentColumn = 0;
			// Print the output, while also adding newlines and hyphens to long words
			for (i = 0; line[i] != '\0'; ++i){
				putchar(line[i]);
				if (line[i] == '\n'){
					++newLineCount;
					currentColumn = 0;
				}
				else{
					++currentColumn;	
				}
				if (currentColumn == (FOLDCOL)){
					putchar('-');
					putchar('\n');
					currentColumn = 0;
				}
			}
			
			// Reset various variables once the folded line is printed.
			putchar('\n');
			i = 0;
			line[0] = '\0';
			columnCount = 0;
			foldPoint = 0;
	
		}
		else if (i < (MAXLINE - 1)){
				line[i] = c;
				line[i + 1] = '\0';
				++i;
		}
	}
	return 0;
}

int isBlank(int c){
	
	if ((c == ' ') || (c == '\t') || (c == '\n')){
		return 1;	
	}
	else{
		return 0;	
	}
}
