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

		// ������ ���� �� ���� �̸� maxi ������ ����
		if (maxi < line[i])
		{
			maxi = line[i];
		}
	}

	low = 1;
	high = maxi;
	answer = 0;

	// low���� high�� ���� �۰ų� ���� ��� while���� ����
	while (low <= high)
	{
		mid = (low + high) / 2;
		// ��ǥ ����
		int centi = 0;

		for (int i = 0; i < K; ++i)
		{
			// �� �� ���� mid������ ���� ���� centi ������ ����
			centi += line[i] / mid;
		}

		if (centi >= N) // centi�� N ���� ũ�ų� ���ٸ�...
		{
			// ���� �� �ִ� ���� ���� �䱸�Ǵ� ���� ������ ���ų� ���ٸ� ������ ���̸� �ø���.
			low = mid + 1;

			if (answer < mid)
			{
				// ������ �ִ��� ������Ʈ
				answer = mid;
			}
		}
		else // centi�� N ���� �۴ٸ�...
		{
			// ���� �� �ִ� ���� ���� �䱸�Ǵ� ���� ������ �۴ٸ� ������ ���̸� ���δ�.
			high = mid - 1;
		}
	}

	cout << answer;

	return 0;
}