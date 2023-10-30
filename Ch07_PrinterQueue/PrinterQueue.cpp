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

	void Print()
	{
		cout << "Print : \n";
		Node* Current = Front;
		while (Current != nullptr)
		{
			cout << Current->Data << " : " << Current->Priority << '\n';
			Current = Current->NextNode;
		}
	}

	Node* GetFront()
	{
		return Front;
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

		RemoveNode->NextNode = nullptr;

		Count--;
		return RemoveNode;
	}

	bool Comparison()
	{
		int BiggerThen = 0;
		Node* Iterator = Front;

		while (Iterator != nullptr)
		{
			if (Iterator->Priority > Front->Priority)
				return false;

			Iterator = Iterator->NextNode;
		}

		return true;
	}

	bool AliveTarget(int TargetNum)
	{
		int ThereIs = 0;
		Node* Iterator = Front;

		while (Iterator != nullptr)
		{
			if (Iterator->Data == TargetNum)
				ThereIs++;

			Iterator = Iterator->NextNode;
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

	// Dequeue를 진행하는데, 뒤에 Priority가 더 높은 노드가 있다면 Dequeue하여 Enqueue
	// 아니면 Dequeue
	// 특정 문서가 몇번째에 Dequeue 되는 지 알아내기

	for (int i = 0; i < N; ++i)
	{
		Queue* NewQueue = new Queue;

		int Size, TargetNum;
		cin >> Size >> TargetNum;

		for (int j = 0; j < Size; ++j)
		{
			int NewPriority;
			cin >> NewPriority;
			NewQueue->Enqueue(j, NewPriority);
		}

		int DequeueCount = 1;

		while (!NewQueue->IsEmpty())
		{
			if (NewQueue->Comparison())
			{
				if (NewQueue->GetFront()->Data == TargetNum)
				{
					cout << DequeueCount << '\n';
					break;
				}
				else
				{
					DequeueCount++;
					NewQueue->Dequeue();
				}
			}
			else
			{
				NewQueue->Enqueue2(NewQueue->Dequeue());
			}
		}

		delete NewQueue;

		/*while (!NewQueue->IsEmpty())
		{
			if (NewQueue->Comparison())
			{
				DequeueCount++;
				if (NewQueue->Dequeue()->Data == TargetNum)
					break;
			}
			else
			{
				NewQueue->Enqueue2(NewQueue->Dequeue());
			}
		}

		cout << DequeueCount;

		delete NewQueue;*/
	}

	return 0;
}