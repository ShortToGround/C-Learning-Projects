#include <stdio.h>



int c = 0;

int main(void){

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


