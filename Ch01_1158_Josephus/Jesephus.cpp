#include <iostream>
#include <vector>

using namespace std;
using ElementType = int;

// ��� ����
class Node
{
public:
	Node* NextNode;
	ElementType Data;
};

// ��� ����
Node* CreateNode(ElementType Data)
{
	Node* NewNode = new Node;
	NewNode->NextNode = nullptr;
	NewNode->Data = Data;

	return NewNode;
}

// ����Ʈ�� ��� �߰�
void AppendNode(Node*& Head, Node* NewNode)
{
	if (Head == nullptr)
	{
		Head = NewNode;
		NewNode->NextNode = Head;
	}
	else
	{
		Node* Tail = Head;
		while (Tail->NextNode != Head)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->NextNode = Head;
	}
}

// ��� �Ҹ�
void DestroyNode(Node* Node)
{
	delete Node;
}

// ��� ����
void RemoveNode(Node*& Head, Node* Remove)
{
	if (Head == Remove)
		Head = Head->NextNode;
	else
	{
		Node* Current = Head;
		while (Current->NextNode != Remove && Current->NextNode != Head)
		{
			Current = Current->NextNode;
		}
		Current->NextNode = Remove->NextNode;
	}
}

// ����Ʈ�� Empty���� Ȯ��
bool IsEmpty(Node* List)
{
	return (List == nullptr);
}

// ����Ʈ ������ ��ȯ
int GetSize(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

Node* GetNodeAt(Node* List, int Location)
{
	Node* Current = List;

	while (Current != nullptr && (--Location > 0))
	{
		Current = Current->NextNode;
	}

	return Current;
}

int main()
{
	int N = 0;
	int K = 0;

	cin >> N >> K;

	Node* List = nullptr;
	Node* NewNode = nullptr;

	// �迭�� N���� ���� �߰�
	for (int i = 0; i < N; ++i)
	{
		NewNode = CreateNode(i + 1);
		AppendNode(List, NewNode);
	}

	Node* NextRemove = GetNodeAt(List, K);

	while (!IsEmpty(List))
	{
		cout << NextRemove->Data << " ";

		Node* CurretRemove = NextRemove;
		NextRemove = GetNodeAt(NextRemove, K);
		RemoveNode(List, CurretRemove);
		//NextRemove = GetNodeAt(List, Current + K);
	}

	//vector<int> Josephus;

	// �迭�� N���� ���� �߰�
	//for (int i = 0; i < N; ++i)
	//{
	//	Josephus.push_back(i + 1);
	//}

	//�迭 �� K ��° ���Ҹ� �����ϰ� ���
	//while (!Josephus.empty())
	//{
	//	if (Josephus.size() < K)
	//	{
	//		int rest = K % Josephus.size();
	//		Josephus.erase(Josephus.begin() + rest);
	//		cout << Josephus.at(rest) << " ";
	//	}
	//	else
	//	{
	//		int Remove = K - 1;
	//		Josephus.erase(Josephus.begin() + Remove);
	//		cout << Josephus.at(Remove) << " ";
	//	}
	//}

	//int Remove = K - 1;

	//for (int i = 0; i < N; ++i)
	//{
	//	if (Josephus.size() < Remove)
	//	{
	//		int rest = Remove - Josephus.size();
	//		Josephus.erase(Josephus.begin() + rest);
	//		cout << Josephus.at(rest) << " ";
	//		Remove += (K - 1);
	//	}
	//	else
	//	{
	//		Josephus.erase(Josephus.begin() + Remove);
	//		cout << Josephus.at(Remove) << " ";
	//		Remove += K;
	//	}
	//}


}