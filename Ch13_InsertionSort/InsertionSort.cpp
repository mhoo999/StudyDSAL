#include <iostream>

using namespace std;

void InsertionSort(int DataSet[], int Length)
{
	int value = 0;

	for (int i = 0; i < Length; ++i)
	{
		if (DataSet[i - 1] <= DataSet[i])
			continue;

		value = DataSet[i];

		for (int j = 0; j < i; ++j)
		{
			if (DataSet[j] > value)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];

	InsertionSort(DataSet, Length);

	for (int i = 0; i < Length; ++i)
		cout << DataSet[i] << " : ";

	return 0;
}