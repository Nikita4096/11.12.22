#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void fill(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % 25 - 16;
}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << '\t';
}

int main()
{
	srand(time(NULL));

	int a = 0;
	int N = 0;
	int M = 0;
A:
	cout << "Number of elements in the array: ";
	cin >> a;
	cout << endl;
	cout << "(For Ex.2) Enter N: ";
	cin >> N;
	cout << endl;
	cout << "(For Ex.3) Enter M: ";
	cin >> M;

	if (a <= 10 /* || M <= 10*/)
	{
		cout << "Number of elements in the array can't be less than 10, please try again " << endl;
		cout << endl;
		goto A;
	}
	int* arr = new int[a];
	int* arr1 = new int[a - 1];
	int* arr3 = new int[a];

	int k = 1;
	cout << "Ex 1" << endl;
	cout << endl;
	fill(arr, a);
	print(arr, a);

	for (int i = 0; i < a; i++)
	{
		*(arr1 + i) = *(arr + i);
	}
	for (int i = 3; i < a; i++)
	{
		*(arr1 + i - 1) = *(arr + i);
	}
	cout << endl;
	print(arr1, a - 1);                               //N1 
	cout << endl;
	cout << endl;
	cout << "Ex 2" << endl;
	cout << endl;
	fill(arr3, a);
	print(arr3, a);
	cout << endl;
	for (int i = 0; i <= k; i++)
	{
		*(arr3 + i) = *(arr1 + i);
		*(arr3 + k + i) = N;
	}
	for (int i = k + 1; i < a; i++)
	{
		*(arr3 + i + 1) = *(arr1 + i);
	}
	print(arr3, a);                                 //N2
	cout << endl;
	cout << endl;
	cout << "Ex. 3" << endl;
	cout << endl;

	int* arr2 = new int[M];
	fill(arr2, M);
	print(arr2, M);

	int even = 0;
	int odd = 0;
	for (int i = 0; i < M; i++)
	{
		if (*(arr2 + i) % 2 == 0)
		{
			even++;

		}
		else
		{
			odd++;
		}

	}
	cout << endl;
	cout << "Even:" << even << endl;
	cout << "Odd: " << odd << endl;
	int* arr_odd = new int[odd];
	int* arr_even = new int[even];
	int x = -1, y = -1;
	for (int i = 0; i < M; i++)
	{
		if (*(arr2 + i) % 2 == 0)
		{
			x++;
			*(arr_even + x) = *(arr2 + i);
		}

	}


	for (int i = 0; i < M; i++)
	{
		if (*(arr2 + i) % 2 != 0)
		{
			y++;
			*(arr_odd + y) = *(arr2 + i);


		}
	}

	print(arr_even, even);
	cout << endl;                                  //N3
	print(arr_odd, odd); 
	delete[] arr;
	delete[] arr1;
	delete[] arr3;
	delete[] arr2;
	delete[] arr_odd;
	delete[] arr_even;
	return 0;
}