#include<stdio.h>
#include<string.h>

int main(void) {

	int n, i, j;
	int GCount;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {

		char str[52] = "\0";

		scanf("%s", str);

		GCount = 0;
		j = 0;

		while (str[j] != '\0') {
			if (str[j] == '(')
			{
				GCount++;
			}
			else if (str[j] == ')')
			{
				GCount--;
			}
			if (GCount < 0) break;
			j++;
		}
		if (GCount == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}