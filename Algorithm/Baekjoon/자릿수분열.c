#include<stdio.h>

int main (void){
	
	int a, e=1, i=0;
	
	printf("숫자를 입력 ! \n");
	scanf("%d", &a);
	
	while(a>=e*10){
		e *= 10;
		i ++;
	} 
	for(;i>=0;i--){
		printf("%d의 자릿수 : %d\n", e, a/e);
		a %= e;
		e /= 10;
	}
}
