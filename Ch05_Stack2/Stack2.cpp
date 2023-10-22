#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int Data;
	Node* NextNode;

	Node(int NewData) : Data(NewData), NextNode(nullptr) {}
};

class Stack
{
public:
	Node* Top;
	Node* List;
	int Count;

	Stack() : Top(nullptr), List(nullptr), Count(0) {}
	~Stack()
	{
		while(List != nullptr)
		{
			Node* DeleteTarget = Top;
			Top = Top->NextNode;
			delete DeleteTarget;
		}
	}

	// 5가지 명령을 처리하는 프로그램 작성
	// 1 X: 정수 X를 스택에 넣는다.(1 <= X <= 100,000)
	void Push(int X)
	{
		Node* NewNode = new Node(X);

		if (IsEmpty() == true)
		{
			Top = NewNode;
			List = NewNode;
		}
		else
		{
			NewNode->NextNode = Top;
			Top = NewNode;
		}

		Count++;
	}

	// 2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
	void PrintPop()
	{
		if (IsEmpty() == true)
			cout << "-1" << '\n';
		else
		{
			cout << Top->Data << '\n';

			Node* DeleteTarget = Top;
			Top = Top->NextNode;
			delete DeleteTarget;

			Count--;
		}
	}

	// 3: 스택에 들어있는 정수의 개수를 출력한다.
	int CountStack()
	{
		return Count;
	}

	// 4: 스택이 비어있으면 1, 아니면 0을 출력한다.
	bool IsEmpty()
	{
		return (Count == 0);
	}

	// 5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
	void PrintTop()
	{
		if (IsEmpty() == true)
			cout << "-1" << '\n';
		else
			cout << Top->Data << '\n';
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

	return 0;
}