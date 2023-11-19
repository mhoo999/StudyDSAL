#include <iostream>

using namespace std;

void FindPosition(int Array[], int Input);

int main()
{
	int N;
	cin >> N;

	int Array[101];

	for (int i = 0; i < N; ++i)
	{
		int Input;
		cin >> Input;
		Array[i] = Input;
	}

	int M;
	cin >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int Value = 0;

		if (Array[i] < M)
		{
		continue;
		}

		Value = Array[i];
		Array[i] = M;

		for (int j = (i+1); j < (N + 1); ++j)
		{
			int Temp = Array[j];
			Array[j] = Value;
			Value = Temp;
		}

		break;
	}

	for (int i = 0; i < (N+1); ++i)
	{
		cout << Array[i] << " ";
	}

	return 0;
}