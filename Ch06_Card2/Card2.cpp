#include <iostream>

using namespace std;

struct Node
{
	int Data;
};

class CQ
{
public:
	int Front;
	int Rear;
	int Capacity;
	int Size;

	Node* Nodes;

	CQ(int Value) : Front(0), Rear(0), Capacity(Value), Size(0), Nodes(new Node[Value+1]) {}
	~CQ()
	{
		delete[] Nodes;
	}
	
	void Enqueue(int NewData)
	{
		int Position = Rear;

		if (Rear == Capacity)
		{
			Rear = 0;
		}
		else
			Rear++;

		Size++;
		Nodes[Position].Data = NewData;
	}

	void Dequeue()
	{
		if (Front == Capacity)
			Front = 0;
		else
			Front++;

		Size--;
	}

	void Shuffle()
	{
		int Temp;

		Temp = Nodes[Front].Data;
		Dequeue();
		Enqueue(Temp);
	}
};

int main()
{
	int N;

	cin >> N;

	CQ* Queue = new CQ(N);

	for (int i = 1; i <= N; ++i)
	{
		Queue->Enqueue(i);
		// cout << (Queue->Nodes[i-1].Data);
	}

	while (Queue->Size != 1)
	{
		Queue->Dequeue();
		Queue->Shuffle();
	}

	cout << Queue->Nodes[Queue->Front].Data;

	return 0;
}