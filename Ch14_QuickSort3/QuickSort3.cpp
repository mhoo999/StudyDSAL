#include <iostream>

using namespace std;

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
		{
			++Left;
		}
		while (DataSet[Right] <= Pivot && Left <= Right)
		{
			--Right;
		}

		if (Left < Right)
		{
			swap(DataSet[Left], DataSet[Right]);
		}
		else
		{
			break;
		}

		swap(DataSet[First], DataSet[Right]);

		return Right;
	}
}

int QuickSort(int DataSet[], int Left, int Right)
{
	int result = 0;

	if (Left < Right)
	{


		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index - 1, Right);
	}

	return result;
}

int main()
{
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

	result = QuickSort(ArrayA, 0, (sizeof(ArrayA)-1));

	cout << result;

	return 0;
}