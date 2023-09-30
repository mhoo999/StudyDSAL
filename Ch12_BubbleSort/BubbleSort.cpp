#include <iostream>

using namespace std;

void BubbleSort(int DataSet[], int Length)
{
	int temp = 0;

	for (int i = 0; i < Length - 1; ++i)
	{
		for (int j = 0; j < Length - (i + 1); ++j)
		{
			if (DataSet[j] > DataSet[j + 1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main(void)
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];

	BubbleSort(DataSet, Length);

	for (int i = 0; i < Length; ++i)
		cout << DataSet[i] << " : ";

	cout << "\n";

	return 0;
}