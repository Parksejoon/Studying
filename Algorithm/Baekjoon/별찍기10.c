#include<stdio.h>

char Star(int n, int i, int j){
	
	if(n<=1) return printf("*");
	
	i %= n;
	j %= n;
	
	if(n/3 <= i && i < n-(n/3) && n/3 <= j && j < n-(n/3)) printf(" ");
	else Star(n/3, i, j);
}

int main(void){
	
	int n, i, j;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) Star(n, i, j);
		printf("\n");
	}
	
	return 0;
}
