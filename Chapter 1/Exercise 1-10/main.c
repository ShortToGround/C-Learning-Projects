#include <stdio.h>


int main(void){

	int c = 0;
	
	while ((c = getchar()) != EOF){
		if (c == '\b'){
			printf("BACKSPACE!\n");
			putchar('\\');
			putchar('b');
		}
		else if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if (c == '\\'){		
			putchar('\\');
			putchar('\\');
		}
		else{
			putchar(c);
		}

	}

return 0;
}


