#include <iostream>
#include <vector>

#define SIZE 10

using namespace std;

template <typename T>
class heap
{
private:
	vector<T> heap_arr;
	
public:
	heap<T>()
	{
		heap_arr.push_back(NULL);
	}

	// 삽입
	void insert(T data)
	{
		heap_arr.push_back(data);

		int ind = heap_arr.size() - 1;

		while (ind > 1 && heap_arr[ind] < heap_arr[ind / 2])
		{
			swap(heap_arr[ind], heap_arr[ind / 2]);
			ind /= 2;
		}
	}

	// 팝
	T pop()
	{
		T return_value = heap_arr[1];
		heap_arr[1] = heap_arr[size()]; heap_arr.pop_back();

		int parent = 1;
		int child = 2;

		while (child <= size())
		{
			if (child + 1 <= size())
			{
				if (heap_arr[child] > heap_arr[child + 1])
				{
					child++;
				}
			}

			if (heap_arr[parent] > heap_arr[child])
			{
				swap(heap_arr[child], heap_arr[parent]);
				parent = child;
			}
			else
			{
				break;
			}

			child *= 2;
		}

		return return_value;
	}

	// 크기
	size_t size()
	{
		return heap_arr.size() - 1;
	}

	// 비어있는지
	bool empty()
	{
		if (size() <= 0)
		{
			return true;
		} 

		return false;
	}

	// 보여주기
	void show()
	{
		for (auto iter = heap_arr.begin() + 1; iter != heap_arr.end(); iter++)
		{
			cout << *iter << endl;
		}
		cout << endl;
	}

private:
	// 스왑
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
};

int main(void)
{
	int arr[SIZE] = { 21, 10, 12, 20, 25, 13, 15 ,22, 42, 11 };
	heap<int> h;

	for (int i = 0; i < SIZE; i++)
	{
		h.insert(arr[i]);
	}

	h.show();

	while (!h.empty())
	{
		cout << h.pop() << endl;
	}
}