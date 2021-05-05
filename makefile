all: heapsort.c mergesort.c quicksort.c sort.h
	gcc heapsort.c -o heapsort.exe 
	gcc mergesort.c -o mergesort.exe
	gcc quicksort.c -o quicksort.exe
