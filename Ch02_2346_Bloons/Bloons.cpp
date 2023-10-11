#include <iostream>
#include <vector>
using namespace std;

int N, Input, Index;
vector<pair<int,int>> V;

void Print()
{
	cout << "Print : ";
	for (int i = 0; i < V.size(); ++i)
	{
		cout << V[i].first << ' ';
	}
	cout << '\n';
}

int main()
{
	cin >> N;
	V = vector<pair<int, int>>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		V[i] = { i + 1, Input };
	}

	while (V.size() > 0)
	{
		cout << V[0].first << ' ';
		int MoveCount = V[0].second;
		V.erase(V.begin());

		if (V.size() == 0) break;

		if (MoveCount > 0)
		{
			MoveCount--;
			while (MoveCount-- > 0)
			{
				V.push_back(V[0]);
				V.erase(V.begin());
			}

			//Print();
		}
		else
		{
			MoveCount *= -1;

			while (MoveCount-- > 0)
			{
				V.insert(V.begin(), V.back());
				V.pop_back();
			}

			//Print();
		}
	}

	return 0;
}