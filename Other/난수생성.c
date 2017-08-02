#include<stdio.h>
#include<time.h>

time_t random(int i)
{
	time_t time_sec = time(NULL);

	time_sec ^= time_sec << 14 ^ (i * 6);
	time_sec ^= time_sec & 0x38506741 >> 2;
	time_sec *= 3 * time_sec >> 17;
	time_sec ^= time_sec << 3;
	time_sec = time(NULL) ^ time_sec;

	return time_sec;
}

int main(void)
{
	int s, e;

	printf("시작값과 끝값을 입력해주세요 ! \n");
	scanf("%d %d", &s, &e);
	printf("%u\n", random(time(NULL)) % e + s);
}
