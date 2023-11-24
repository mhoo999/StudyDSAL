#include <iostream>

using namespace std;

int VerificationArray(int ArrayA[], int ArrayB[], int N)
{
	int Count = 0;

	for (int i = 0; i < N; ++i)
	{
		// cout << ArrayA[i] << " : ";

		if (ArrayA[i] == ArrayB[i])
		{
			++Count;
		}
	}

	if (Count == N)
	{
		return 1;
	}

	return 0;
}

int Partition(int ArrayA[], int ArrayB[], int Left, int Right, int &EqualCount)
{
	int First = Left;
	int Pivot = ArrayA[Left];

	++Left;

	while (Left < Right)
	{
		while (ArrayA[Left] <= Pivot && Left < Right)
		{
			++Left;
		}

		while (ArrayA[Right] >= Pivot && Right >= Left)
		{
			--Right;
		}

		if (Left < Right)
		{
			swap(ArrayA[Left], ArrayA[Right]);
			EqualCount += VerificationArray(ArrayA, ArrayB, Right+1);
		}
		else
		{
			break;
		}
	}

	swap(ArrayA[First], ArrayA[Right]);
	return Right;
}

void QuickSort(int ArrayA[], int ArrayB[], int Left, int Right, int &EqualCount)
{
	if (Left < Right)
	{
		int Index = Partition(ArrayA, ArrayB, Left, Right, EqualCount);

		QuickSort(ArrayA, ArrayB, Left, Index - 1, EqualCount);
		QuickSort(ArrayA, ArrayB, Index+1, Right, EqualCount);
	}
}

int main()
{
	int EqualCount = 0;
	int result = 0;
	int N;
	cin >> N;

	int ArrayA[10000] = { 0 };
	int ArrayB[10000] = { 0 };

	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;

		ArrayA[i] = a;
	}

	for (int i = 0; i < N; ++i)
	{
		int b;
		cin >> b;

		ArrayB[i] = b;
	}

	EqualCount += VerificationArray(ArrayA, ArrayB, N-1);


	QuickSort(ArrayA, ArrayB, 0, N, EqualCount);


	if (EqualCount > 0)
	{
		result = 1;
	}

	cout << result;

	return 0;
}