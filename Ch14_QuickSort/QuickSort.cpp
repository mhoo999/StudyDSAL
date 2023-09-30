#include <iostream>

using namespace std;

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First]; // 기준 요소

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right) // Left, Right 는 양 끝에서부터 기준 대상보다 크거나 작은 요소를 탐색, 두 변수가 만나면 break;
			++Left;

		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			swap(DataSet[Left], DataSet[Right]);
		else
			break;
	}

	swap(DataSet[First], DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1); // 재귀 호출
		QuickSort(DataSet, Index + 1, Right); // 재귀 호출
	}
}

int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];

	QuickSort(DataSet, 0, Length - 1);

	for (int i = 0; i < Length; ++i)
		cout << DataSet[i] << " : ";

	return 0;
}