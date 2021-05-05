#include	<stdio.h>
#include	<stdlib.h>
#define	NUM	1000000

int main(){
	int n, i, j=0;
	char c;

	while(j < NUM){
		for(i=0;i<100;i++){
			n = rand() % 52;
			if(n < 26){
				c = 'a' + n;
				printf("%c", c);
			}
			else if(n >= 26){
				c = 'A' + n - 26;
				printf("%c", c);
			}
		}
		printf("\n");
		j++;
	}
	return 0;
}
