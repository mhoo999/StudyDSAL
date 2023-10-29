#include <iostream>

using namespace std;

struct Node
{
	int Data;
	int Priority;
	Node* NextNode;

	Node(int NewData, int NewPriority) : Data(NewData), Priority(NewPriority), NextNode(nullptr) {}
};

class Queue
{
public:
	Node* Front;
	Node* Rear;
	int Count;

	Queue() : Front(nullptr), Rear(nullptr), Count(0) {}
	~Queue()
	{
		while (!IsEmpty())
		{
			Node* RemoveTarget = Front;
			Front = Front->NextNode;
			delete RemoveTarget;
		}
	}

	bool IsEmpty()
	{
		return Count == 0;
	}

	void Enqueue(int NewData, int NewPriority)
	{
		Node* NewNode = new Node(NewData, NewPriority);

		if (Front == nullptr)
		{
			Front = NewNode;
			Rear = NewNode;
		}
		else
		{
			Rear->NextNode = NewNode;
			Rear = NewNode;
		}

		Count++;
	}

	void Enqueue2(Node* NewNode)
	{
		
		Rear->NextNode = NewNode;
		Rear = NewNode;

		Count++;
	}

	Node* Dequeue()
	{
		Node* RemoveNode = Front;

		if (Front->NextNode == nullptr)
		{
			Front = nullptr;
			Rear = nullptr;
		}
		else
		{
			Front = Front->NextNode;
		}

		Count--;
		return RemoveNode;
	}

	bool Comparison()
	{
		int BiggerThen = 0;
		Node* Interator = Front;

		while (Interator != nullptr)
		{
			if (Interator->Priority > Front->Priority)
				BiggerThen++;

			Interator = Interator->NextNode;
		}

		if (BiggerThen == 0)
			return true;
		else
			return false;
	}

	bool AliveTarget(int TargetNum)
	{
		int ThereIs = 0;
		Node* Interator = Front;

		while (Interator != nullptr)
		{
			if (Interator->Data == TargetNum)
				ThereIs++;

			Interator = Interator->NextNode;
		}

		if (ThereIs == 0)
			return false;
		else
			return true;
	}
};

int main()
{
	int N;
	cin >> N;

	Queue* NewQueue = new Queue;

	for (int i = 0; i < N; ++i)
	{
		int Size, TargetNum;
		cin >> Size >> TargetNum;

		for (int j = 0; j < Size; ++j)
		{
			int NewPriority;
			cin >> NewPriority;
			NewQueue->Enqueue(j, NewPriority);
		}

		//Node* TargetNode = NewQueue->Front;

		//for (int j = 0; j < TargetNum; ++j)
		//{
		//	TargetNode = TargetNode->NextNode;
		//}

		// Node* Comparison = NewQueue->Front;
		int DequeueCount = 0;

		while (NewQueue->AliveTarget(TargetNum))
		{
			if (NewQueue->Comparison())
			{
				NewQueue->Dequeue();
			}
			else
			{
				NewQueue->Enqueue2(NewQueue->Dequeue());
			}

			DequeueCount++;
		}

		cout << DequeueCount;
	}

	// Dequeue를 진행하는데, 뒤에 Priority가 더 높은 노드가 있다면 Dequeue하여 Enqueue
	// 아니면 Dequeue
	// 특정 문서가 몇번째에 Dequeue 되는 지 알아내기


	return 0;
}