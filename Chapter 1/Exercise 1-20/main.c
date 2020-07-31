#include <stdio.h>

#define TAB_LENGTH		8		//Tab length in spaces


int main(void){
	
	int c, i = 0, spacesNeeded;
	
	while ((c = getchar()) != EOF){
		// if newline is detected then the column counter "i" needs to be reset to 0
		if (c == '\n'){
			putchar(c);
			i = 0;
		}
		// If a tab is detected, then it will see how many spaces are needed to reach the next tab block
		else if (c == '\t'){
			// the column counter "i" only counts in blocks of 8, so all we have to do is 
			//	 see how many spaces we are shy of to the next block
			spacesNeeded = (TAB_LENGTH - i);
			for (i = 0; i != spacesNeeded; i++){
				putchar(' ');
			}
			// Because the spaces will push us to the next tab block, the column counter is reset
			i = 0;
		}
		else{
			putchar(c);
			// have to offset the column counter by 1 due to the variable starting at 0
			if (i < TAB_LENGTH - 1){
				++i;	
			}
			else{
				i = 0;	
			}
		}
	}
	return 0;
}



