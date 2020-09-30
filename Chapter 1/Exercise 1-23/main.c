#include <stdio.h>

// This has more if's than Obama did when he lost his teleprompter 
// I didn't bother cleaning this up.. its works as is.... I think.

int main(void){
	
	int c, lastChar = 0, quoteChar = 0;
	int inComment = 0;
	int inQuotes = 0;
	int lineComment = 0;

	while ((c = getchar()) != EOF){
		if ((c == '"') || (c == '\'')){
			if (!inQuotes){
				inQuotes = 1;
				quoteChar = c;
				putchar(c);
			}
			else{
				if (c == quoteChar){
					inQuotes = 0;
					quoteChar = 0;
					putchar(c);
				}
			}
		}
		else if (c == '\n'){
			if (lineComment && inComment){
				inComment = 0;
				lineComment = 0;
				lastChar = 0;
				putchar(c);
			}
			else{
				putchar(c);
			}
		}
		else if (c == '/'){
			if (!inQuotes){
				if (!inComment){
					if (lastChar == '/'){
						inComment = 1;
						lineComment = 1;
						lastChar = 0;
					}
					else{
						lastChar = c;
					}
				}
				else{
					if (lastChar == '*'){
						inComment = 0;
						lastChar = 0;
					}

				}
			}
			else{
				putchar(c);
			}
		}
		else if (c == '*'){
			if (!inQuotes){
				if (inComment){
					lastChar = c;
				}
				else if (lastChar == '/'){
						inComment = 1;
						lastChar = 0;
				}
				else{
					putchar(lastChar);
					putchar(c);
				}
			}
			else{
				putchar(c);
			}
		}
		else{
			if (!inComment){
				putchar(c);
			}
		}
	}
	
	return 0;
}
