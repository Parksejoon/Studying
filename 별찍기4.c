#include<stdio.h>

int main(void){
	int n, i, j=1;
	scanf("%d", &n);
	for(i=1; i<=n*n; i++){
		if(i==n*(j-1)+1){
			printf(" ");
		}else
			printf("*");
		if(i==n*j){
			j++;
			printf("\n");
		}
	}
}
