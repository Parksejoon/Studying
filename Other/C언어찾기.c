#include<stdio.h>

int main(void){
	
	int i=0, count=0, ccount=0;
	char c[101];
	
	printf("���ڿ��� �Է��ϼ� .. \n");
	scanf("%s", c);
	
	while(c[i] != '\0'){
		if(c[i] == 'C' || c[i] == 'c'){
			count++;
			if(c[i+1] == 'C' || c[i+1] == 'c') ccount++;
		}
		i++;
	}
	
	printf("�ε� ..! \nC�� ���� : %d\nCC�� ���� : %d", count, ccount);
}
