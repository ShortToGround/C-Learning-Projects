#include <stdio.h>

// Counts the number of spaces, tabs, and newlines then prints them at the end.

int last, c;
int spaces = 0, tabs = 0, newlines = 0;

int main(void){
	
	while ((c = getchar()) != EOF){
		
		// Used to keep track of the character entered before "EOF"
		last = c;
		
		// If the current char is a space
		if (c == ' '){
			++spaces;
		}
		else if (c == '\t'){
			++tabs;
		}
		else if (c == '\n'){
			++newlines;
		}
	}
	
	// Added this in to make the output look neater when you don't press enter before sending the "EOF"
	if (last != '\n'){
		// If the last character entered before EOF wasn't a newline, print one.
		printf("\n");
	}
	
	printf("Spaces:%d Tabs:%d Newlines: %d\n", spaces, tabs, newlines);
	
return 0;
}


