#include<stdio.h>

char* week[7] =
{
	"SUN",
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT"
};
int month, day;

void Input(void)
{
	scanf("%d %d", &month, &day);
}

void Solve(void)
{
	int result = (month - 1) * 31 + day - ((month - 1)  / 2);

	if (month >= 9) result += 1;
	if (month >= 10 && month % 2 == 0) result -= 1;
	if (month >= 3) result -= 2;

	printf("%s\n", week[result % 7]);
}

int main(void)
{
	Input();

	Solve();
}