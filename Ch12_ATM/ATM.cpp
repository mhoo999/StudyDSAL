#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int MinimumTime = 0;

	int N;
	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		int p;

		cin >> p;

		v.push_back(p);
	}

	sort(v.begin(), v.end());

	int Temp = 0;

	for (int i = 0; i < N; ++i)
	{
		Temp += v[i];
		MinimumTime += Temp;
	}

	cout << MinimumTime;

	return 0;
}