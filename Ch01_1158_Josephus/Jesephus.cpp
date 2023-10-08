#include <iostream>
#include <vector>

using namespace std;
using ElementType = int;

// 노드 선언
class Node
{
public:
	Node* NextNode;
	ElementType Data;
};

// 노드 생성
Node* CreateNode(ElementType Data)
{
	Node* NewNode = new Node;
	NewNode->NextNode = nullptr;
	NewNode->Data = Data;

	return NewNode;
}

// 리스트에 노드 추가
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

// 노드 소멸
void DestroyNode(Node* Node)
{
	delete Node;
}

// 노드 삭제
void RemoveNode(Node*& Head, Node* Remove)
{
	if (Head == Remove)
	{
		Head = Head->NextNode;
		Head->NextNode = Remove->NextNode;
	}
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

// 리스트가 Empty인지 확인
bool IsEmpty(Node* List)
{
	return (List == nullptr);
}

// 리스트 사이즈 반환
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

	if (Current == List)
		return Current->NextNode;

	return Current;
}

int main()
{
	int N = 0;
	int K = 0;

	cin >> N >> K;

	Node* List = nullptr;
	Node* NewNode = nullptr;

	// 배열에 N개의 원소 추가
	for (int i = 0; i < N; ++i)
	{
		NewNode = CreateNode(i + 1);
		AppendNode(List, NewNode);
	}

	// 첫 번째로 삭제할 요소 선언
	Node* NextRemove = GetNodeAt(List, K);

	// 첫 번째로 삭제할 요소 cout, 다음 요소 저장.. N번 반복
	for (int i = 0; i < N; ++i)
	{
		cout << NextRemove->Data << " ";

		Node* CurretRemove = NextRemove;
		NextRemove = GetNodeAt(NextRemove, K + 1);

		RemoveNode(List, CurretRemove);
		DestroyNode(CurretRemove);

		//NextRemove = GetNodeAt(List, Current + K);
	}

	return 0;

	/*
	2차 시도, while로 하니까 마지막에 계속 쓰레기 값 남음..
	위 코드로 Visual Studio에서 실행 시, VS가 자동으로 잘 못된 포인터의 값을 잡아주지만(?)
	백준에서는 마지막에 쓰레기 값을 바라보는 포인터가 있어서 실패하는듯?
	*/

	//while (!IsEmpty(List))
	//{
	//	cout << NextRemove->Data << " ";

	//	Node* CurretRemove = NextRemove;

	//	//if (GetCount(List) != 1)
	//	NextRemove = GetNodeAt(NextRemove, K + 1);

	//	RemoveNode(List, CurretRemove);
	//	DestroyNode(CurretRemove);

	//	//NextRemove = GetNodeAt(List, Current + K);
	//}

	
	/*
	1차 시도, vector는 순환이 안 되어서 실패
	*/

	//vector<int> Josephus;

	// 배열에 N개의 원소 추가
	//for (int i = 0; i < N; ++i)
	//{
	//	Josephus.push_back(i + 1);
	//}

	//배열 내 K 번째 원소를 제거하고 출력
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