#include <stdio.h>

#define MAXLINE		255		// Max input line length

int reverse(char line[]);


int main(void){
	
	char s[MAXLINE];
	int c, i = 0;
	
	while ((c = getchar()) != EOF){
		
		if (c == '\n'){
			s[i] = '\0';
			reverse(s);
			i = 0;
		}
		else{
			// Added a "- 1" here to in order to guarantee room for the \0 character
			if (i < MAXLINE - 1){
				s[i] = c;
				++i;
			}
		}
	}
	
	
	return 0;
}


int reverse(char s[]){
	
	int i, j;
	
	// Because of the constraint of only passing the reverse function one arg,
	//	we need to figure out where my string ends
	for (i = 0; s[i] != '\0'; ++i){}
	
	// Now we just loop from there to reverse the string
	for (j = i - 1; j >= 0; --j){
		putchar(s[j]);
	}
	printf("\n");
	return 0;
}
