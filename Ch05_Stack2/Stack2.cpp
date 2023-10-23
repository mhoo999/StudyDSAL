#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int Data;
	Node* NextNode;

	Node(int NewData) : Data(NewData), NextNode(nullptr) {}
};

class Stack
{
public:
	Node* Top;
	int Count;

	Stack() : Top(nullptr), Count(0) {}
	~Stack()
	{
		while(Top != nullptr)
		{
			Node* DeleteTarget = Top;
			Top = Top->NextNode;
			delete DeleteTarget;
		}
	}

	// 5���� ������ ó���ϴ� ���α׷� �ۼ�
	// 1 X: ���� X�� ���ÿ� �ִ´�.(1 <= X <= 100,000)
	void Push(int X)
	{
		Node* NewNode = new Node(X);

		if (IsEmpty())
		{
			Top = NewNode;
		}
		else
		{
			NewNode->NextNode = Top;
			Top = NewNode;
		}

		Count++;
	}

	// 2: ���ÿ� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
	void PrintPop()
	{
		if (!IsEmpty())
		{
			cout << Top->Data << '\n';

			Node* DeleteTarget = Top;
			Top = Top->NextNode;
			delete DeleteTarget;

			Count--;
		}
		else
			cout << "-1" << '\n';
	}

	// 3: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	int CountStack()
	{
		return Count;
	}

	// 4: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	bool IsEmpty()
	{
		return (Count == 0);
	}

	// 5: ���ÿ� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
	void PrintTop()
	{
		if (!IsEmpty())
			cout << Top->Data << '\n';
		else
			cout << "-1" << '\n';
	}
};

int main()
{
	Stack* NewStack = new Stack;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Order;
		int X;

		cin >> Order;

		if (Order == 1)
			cin >> X;

		if (Order == 1)
			NewStack->Push(X);
		else if (Order == 2)
			NewStack->PrintPop();
		else if (Order == 3)
			cout << NewStack->CountStack();
		else if (Order == 4)
			cout << NewStack->IsEmpty();
		else
			NewStack->PrintTop();
	}

	delete NewStack;

	return 0;
}