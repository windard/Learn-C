/******************************************************************************
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,min,index,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	for (i = 0; i < N; i++) {
		min = a[i];
		index = i;
		for (j = i; j < N; j++) {
			if (a[j] < min){
				min = a[j];
				index = j;
			}
		}
		t = a[i];
		a[i] = a[index];
		a[index] = t;
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}

*******************************************************************************/

#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (a[j] < a[i]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}