#include<stdio.h>

int repeat=0;

int division(int n);

int main(void){
	
	int i, n;
	
	scanf("%d", &n);
	division(n);
	printf("%d", repeat);
	return 0;
}

int division(int n){
	
	int t, o, temp;
	
	if(n<10){
		t = 0;
		o = n;
	}else{
		t = n/10;
		o = n%10;
	}
	
	do{
		repeat ++;
		
		temp = o;
		o = (t+o)%10;
		t = temp;
	}while(t*10+o!=n);
}
