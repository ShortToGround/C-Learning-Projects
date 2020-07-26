#include <stdio.h>

#define MAXLINE 1000		// Max input line length

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void){
	
	int len;				// current line length
	int max;				// maxium length seen so farcalloc
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here
	
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0){
		if (len > max){
			max = len;
			copy(longest, line);
		}
		// Originally I did this in one printf but I changed it just for code clarity
		printf("\n########################\n");
		printf("%d\n", len - 1);
		printf("%s\n", line);
		printf("########################\n");		
	}
	
	if (max > 0){	// there was a line
		printf("%s", longest);
		printf("\n%d\n", max - 1);
	}
	
	return 0;
}


int get_line(char s[], int lim){
	
	int c, i;
	
	for (i = 0; ((i < lim - 1) && ((c=getchar()) != EOF) && (c != '\n')); ++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
