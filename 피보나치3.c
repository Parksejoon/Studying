#include<stdio.h>

int zero=0, one=0;
int n=0, temp3;

int f(int n);

int main(void){
	
	int t, i;
	
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d", &n);
		if(n==0){
			printf("1 0\n");
			continue;
		}else
		f(n-2);
		zero = temp3;
		f(n-1);
		one = temp3;
		printf("%d %d\n", zero, one);
	}
}

int f(int n){
	int a=0, b=1, temp;
	int i;
	
	for(i=0; i<n; i++){
		temp = b;
		b = a+b;
		a = temp;
	}
	if(n<0) temp3 = 0;
	else temp3 = b;
}
