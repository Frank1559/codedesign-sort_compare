#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#include	"sort.h"
#define	NUM	1000000


int main(int argc, char **argv){
	int i;
	char *list[NUM];
	char *str;
	int *a;
	struct  timeval start;
    	struct  timeval end;
	unsigned  long diff;	
	
	if(argc == 1){
		a = malloc(sizeof(int) * NUM);
   		for(i = 0; i<NUM; i++){
        		scanf("%d", &a[i]);
    		}
		gettimeofday(&start, NULL);
    		merge_sort(a, 0, NUM-1);
		gettimeofday(&end, NULL);
    		/*for(i = 0; i<NUM; i++){
        		printf("%d\n", a[i]);
    		}*/
		diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    		printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	}
	else if(argc == 2 && strcmp(argv[1], "-i") == 0){
		a = malloc(sizeof(int) * NUM);
    		for(i = 0; i<NUM; i++){
        		scanf("%d", &a[i]);
    		}
		gettimeofday(&start, NULL);
    		merge_sort(a, 0, NUM-1);
		gettimeofday(&end, NULL);
    		/*for(i = 0; i<NUM; i++){
        		printf("%d\n", a[i]);
    		}*/
		diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    		printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	}
	else if(argc == 2 && strcmp(argv[1], "-s") == 0){
		str = malloc(sizeof(char) * 101);
		for(i = 0; i<NUM; i++){
			scanf("%s", str);
			list[i] = str;
			str = malloc(sizeof(char) * 101);
		}
		gettimeofday(&start, NULL);
		s_merge_sort(list, 0, NUM-1);
		gettimeofday(&end, NULL);
		/*for(i = 0; i<NUM; i++){
			printf("%s\n", list[i]);
		}*/
		diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    		printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);

	}
	return 0;
}
