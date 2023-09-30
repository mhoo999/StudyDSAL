#include "BinarySearchTree.h"

void PrintSearchResult(int SearchTarget, BSTNode* Result)
{
	if (Result != nullptr)
		cout << "Found : " << Result->Data << endl;
	else
		cout << "Not Found : " << SearchTarget << endl;
}

int main()
{
	BSTNode* Tree = BST_CreateNode(123); // 노드 생성
	BSTNode* Node = nullptr;

	BST_InsertNode(Tree, BST_CreateNode(22)); // 트리에 노드 추가
	BST_InsertNode(Tree, BST_CreateNode(9918));
	BST_InsertNode(Tree, BST_CreateNode(424));
	BST_InsertNode(Tree, BST_CreateNode(17));
	BST_InsertNode(Tree, BST_CreateNode(3));

	BST_InsertNode(Tree, BST_CreateNode(98));
	BST_InsertNode(Tree, BST_CreateNode(34));

	BST_InsertNode(Tree, BST_CreateNode(760));
	BST_InsertNode(Tree, BST_CreateNode(317));
	BST_InsertNode(Tree, BST_CreateNode(1));

	int SearchTarget = 17;
	Node = BST_SearchNode(Tree, SearchTarget);
	PrintSearchResult(SearchTarget, Node);

	SearchTarget = 117;
	Node = BST_SearchNode(Tree, SearchTarget);
	PrintSearchResult(SearchTarget, Node);

	BST_InorderPrintTree(Tree); // 트리 출력
	cout << '\n';

	cout << "Removing 98 ...\n"; // 특정 노드 삭제

	Node = BST_RemoveNode(Tree, nullptr, 98);
	BST_DestroyNode(Node);

	BST_InorderPrintTree(Tree);
	cout << '\n';

	cout << "Inserting 111...\n"; // 새 노드 삽입

	BST_InsertNode(Tree, BST_CreateNode(111));
	BST_InorderPrintTree(Tree);
	cout << '\n';

	BST_DestroyTree(Tree); // 트리 소멸

	return 0;
}