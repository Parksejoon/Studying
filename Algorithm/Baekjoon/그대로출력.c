#include<stdio.h>
#include<memory.h>

int main(void){
	
	int i=0;
	
	while(i<=100){
		
		i++;
		char type[10000]={0};
		
		scanf(" %[^\n]s", type);
		printf("%s\n", type);
	}
}
