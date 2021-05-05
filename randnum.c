#include	<stdio.h>
#include	<stdlib.h>

int main(){
	int n, i=0;
	int Max = 1000000; 
	while(i<Max){
		n = rand();
		printf("%d\n", n);
		i++;
	}
	return 0;
}
