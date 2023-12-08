#include <iostream>

using namespace std;

int K, N, answer;
int line[10001];
int maxi = 0;
long long mid, high, low;

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; ++i)
	{
		cin >> line[i];

		// 랜선의 가장 긴 값을 미리 maxi 변수에 저장
		if (maxi < line[i])
		{
			maxi = line[i];
		}
	}

	low = 1;
	high = maxi;
	answer = 0;

	// low값이 high값 보다 작거나 같은 경우 while문을 실행
	while (low <= high)
	{
		mid = (low + high) / 2;
		// 목표 변수
		int centi = 0;

		for (int i = 0; i < K; ++i)
		{
			// 각 랜 선을 mid값으로 나눈 값을 centi 변수에 저장
			centi += line[i] / mid;
		}

		if (centi >= N) // centi가 N 보다 크거나 같다면...
		{
			// 만들 수 있는 랜선 수가 요구되는 랜선 수보다 많거나 같다면 전선의 길이를 늘린다.
			low = mid + 1;

			if (answer < mid)
			{
				// 랜선의 최댓값을 업데이트
				answer = mid;
			}
		}
		else // centi가 N 보다 작다면...
		{
			// 만들 수 있는 랜선 수가 요구되는 랜선 수보다 작다면 전선의 길이를 줄인다.
			high = mid - 1;
		}
	}

	cout << answer;

	return 0;
}