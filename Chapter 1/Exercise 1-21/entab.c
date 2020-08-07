#include <stdio.h>

#define TABSTOP		8			// Tab length in spaces


int main(void){
	
	int c;							// Holds the current character
	int columnpos = 1; 				// Cycles though the current position of the char relative to the tab stop - Starts on col 1
	int spaces = 0;					// Keeps track of the number of spaces entered in a row
	int tabsOut;					// Number of tabs that will be output
	int spacesOut;					// Number of spaces that will be output
	int spaceStart;					// The column position where a space is first entered
	int nextBlock;					// The next tab stop column position relative to the current character
	
	while ((c = getchar()) != EOF){
		
		if (c == ' '){
			if (spaces > 0){
				++spaces;
			}
			else{
				spaceStart = columnpos;
				++spaces;
				// Calculates the next tab stop location, vital for outputing the correct data
				nextBlock = columnpos + (TABSTOP - (columnpos % TABSTOP));
			}
		}
		else{
			if (spaces > 0){
				// If the spaces aren't enough to get to the next tab stop, just print them all
				if (((spaceStart - 1) + spaces) < nextBlock){
					for (; spaces > 0; --spaces){
						putchar(' ');	
					}
					putchar(c);
				}
				// If the spaces at least reach the next tab stop
				else{
					// We're going to insert a tab to replace the spaces from the
					// 	spaceStart column to the next tab stop
					
					// Here we adjust the space counter for the spaces that are to be removed by the next tab
					spaces = spaces - (nextBlock - (spaceStart - 1));
					// Put the first tab, now the rest of the calculation will be a little easier
					// Since we are starting on a tab stop
					putchar('\t');
					spacesOut = (spaces % TABSTOP);
					tabsOut = ((spaces - spacesOut) / TABSTOP);
					// Output the calculated tabs
					for (; tabsOut > 0; --tabsOut){
						putchar('\t');	
					}
					// Output the calculated spaces
					for (; spacesOut > 0; --spacesOut){
						putchar(' ');	
					}
					putchar(c);
					spaces = 0;
				}
			}
			else{
				putchar(c);	
				spaces = 0;
			}
		}

		
		// This section deals with incrementing the columnpos or reseting it if a newline is entered
		if (c == '\n'){
			columnpos = 1;
			spaces = 0;
		}
		else{
			++columnpos;	
		}
	}
	return 0;
}

