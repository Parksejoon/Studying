#include<stdio.h>

int z, o;
int fibonacci(int n){
	
	if(n==0){
		z ++;
		return 0;
	}else if(n==1){
		o ++;
		return 1;
	}else {
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main(void){
	
	int t, n;
	int i;
	
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d", &n);
		z=0, o=0;
		fibonacci(n);
		printf("%d %d\n", z, o);
	}
}

