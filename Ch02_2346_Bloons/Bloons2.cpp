#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<pair<int, int>> v;

	int N, Data;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Data;
		v[i] = { i + 1, Data };
	}


}