#include<stdio.h>
#include<malloc.h>

int main(void){
	
	int n, i, j;
	int temp;
	
	scanf("%d", &n);
	
	int *num = (int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++){
		scanf("%d", &num[i]);
		temp = num[i];
		for(j=i-1; num[j] > temp && j>=0; j--){
			num[j+1] = num[j];
		}
		num[j+1] = temp;
	}
	
	for(j=0; j<n; j++){
		printf("%d ", num[j]);
	}
	
	free(num);
	
	return 0;
}
