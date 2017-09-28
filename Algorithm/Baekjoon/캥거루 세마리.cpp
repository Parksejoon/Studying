#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	return 0;
}

int main(void)
{
	int arr[3];
	
	cin >> arr[0] >> arr[1] >> arr[2];
	qsort(arr, 3, sizeof(int), compare);

	cout << max(arr[2] - arr[1], arr[1] - arr[0]) - 1 << "\n";
}