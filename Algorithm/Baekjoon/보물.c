#include<stdio.h>
#include<malloc.h>

int main(void) {

	int i, j;
	int n, big = -1, small = 101;
	int ang=0;
	int big_p, small_p;

	scanf("%d", &n);

	int *A = (int *) malloc(sizeof(int)*n);
	int *B = (int *) malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	for (i = 0; i < n; i++) scanf("%d", &B[i]);

	for (i = 0; i < n; i++) {
		big = -1;
		small = 101;
		for (j = 0; j < n; j++) {
			if (A[j] < small) {
				small_p = j;
				small = A[j];
			}
		}
		A[small_p] = 101;
		for (j = 0; j < n; j++) {
			if (B[j] > big) {
				big_p = j;
				big = B[j];
			}
		}
		B[big_p] = -1;
		ang += big*small;
	}
	printf("%d\n", ang);

	return 0;
}