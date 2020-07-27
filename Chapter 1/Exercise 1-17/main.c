#include <stdio.h>

#define MAXLINE		255		// Max input line length

int blankArray(char line[]);

int main(void){
	
	int c, i = 0;
	char line[MAXLINE];
	
	while ((c = getchar()) != EOF){
		if ((c != '\n') && (i < MAXLINE)){
			line[i] = c;
			++i;
		}
		else{
			if (c == '\n'){
				if (i > 80){
					printf("\n%s\n\n", line);
					blankArray(line);
					i = 0;
				}
				else{
					blankArray(line);
					i = 0;
				}
			}
		}
	}
	
	return 0;
}



int blankArray(char line[]){
	
	int i;
	
	for (i = 0; i < MAXLINE; i++){
		line[i] = '\0';
	}
	
	return 0;
}
