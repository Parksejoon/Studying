#include<stdio.h>
#include<malloc.h>

int main(void) {

	int i, j, temp;
	int n, size, k;

	printf("�迭�� ũ�⸦ �Է��ϼ��� !\n");
	scanf("%d", &size);

	int *num = (int *) malloc(sizeof(int)*size);

	printf("�迭�� �Է��ϼ��� ! \n");
	for (i = 0; i < size; i++)
		scanf("%d", &num[i]);

	int r = size - 1, l = 0, m;

	printf("ã�� ���ڸ� �Է��ϼ��� ! \n");
	scanf("%d", &k);

	for (i = 0; i < size; i++) {
		temp = num[i];
		for (j = i - 1; num[j] > temp && j >= 0; j--) {
			num[j + 1] = num[j];
		}
		num[j + 1] = temp;
	}

	m = (l + r) / 2;

	while(l <= r && num[m] != k) {
		if (k > num[m]) l = m + 1;
		else r = m - 1;
		m = (l + r) / 2;
	}

	if (l > r) printf("�׵����� ����..\n");
	else printf("�־�..\n");

	return 0;

}