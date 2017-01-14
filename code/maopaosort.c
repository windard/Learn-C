/********************************************************************************
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i; j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}

*********************************************************************************/

#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t,flag;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {
		flag = 1;
		for (j = 0; j < N - i; j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}