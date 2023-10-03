#include "RedBlackTree.h"

extern RBTNode* Nil;

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = new RBTNode;
	NewNode->Parent = nullptr;
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	NewNode->Data = NewData;
	NewNode->color = Color::BLACK;

	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	delete Node;
}

void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
		RBT_DestroyTree(Tree->Right);
	if (Tree->Left != Nil)
		RBT_DestroyTree(Tree->Left);

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return nullptr;

	if (Tree->Data > Target)
		RBT_SearchNode(Tree->Left, Target);
	else if (Tree->Data < Target)
		RBT_SearchNode(Tree->Right, Target);
	else
		return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return nullptr;

	if (Tree->Left == Nil)
		return Tree;
	else
		RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode*& Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->color = Color::RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode*& Tree, RBTNode* NewNode)
{
	if (Tree == nullptr)
		Tree = NewNode;

	if (Tree->Data < NewNode->Data)
	{
		if (Tree->Right == Nil)
		{
			Tree->Right = NewNode;
			NewNode->Parent = Tree;
		}
		else
			RBT_InsertNodeHelper(Tree->Right, NewNode);
	}
	else if (Tree->Data > NewNode->Data)
	{
		if (Tree->Left == Nil)
		{
			Tree->Left = NewNode;
			NewNode->Parent = Tree;
		}
		else
			RBT_InsertNodeHelper(Tree->Left, NewNode);
	}
}

void RBT_RebuildAfterInsert(RBTNode*& Root, RBTNode* X)
{
	while (X != Root && X->Parent->color == Color::RED) // X가 Root가 아니고 X의 Parent의 Color가 RED일 경우
	{
		if (X->Parent == X->Parent->Parent->Left) // X의 Parent가 할아버지 노드의 Left 자식일 경우
		{
			RBTNode* Uncle = X->Parent->Parent->Right; // 삼촌 노드 정의
			if (Uncle->color == Color::RED) // 삼촌 노드도 RED일 경우(Parent, Uncle == RED)
			{
				X->Parent->color = Color::BLACK;  // X의 부모를 BLACK
				Uncle->color = Color::BLACK; // 삼촌을 BLACK
				X->Parent->Parent->color = Color::RED; // 할아버지를 RED

				X = X->Parent->Parent; // X = 할아버지 노드
			}
			else // 삼촌 노드가 BLACK일 경우
			{
				if (X == X->Parent->Right) // X가 부모의 Right 노드일 경우
				{
					X = X->Parent; // X = 부모 노드
					RBT_RotateLeft(Root, X); // 부모 노드를 중심으로 좌회전
				}

				X->Parent->color = Color::BLACK; // X의 컬러 BLACK
				X->Parent->Parent->color = Color::RED; // X 할아버지 컬러 RED

				RBT_RotateRight(Root, X->Parent->Parent); // X 할아버지 중심으로 우회전
			}
		}
		else // X의 Parent가 할아버지 노드의 Right 자식일 경우(위 케이스와 Left<->Right 교체 진행)
		{
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->color == Color::RED)
			{
				X->Parent->color = Color::BLACK;
				Uncle->color = Color::BLACK;
				X->Parent->Parent->color = Color::RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Left)
				{
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}

				X->Parent->color = Color::BLACK;
				X->Parent->Parent->color = Color::RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	Root->color = Color::BLACK;
}

void RBT_RotateRight(RBTNode*& Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left; // Left Child 노드를 Parent->Left 값으로 초기화

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
		LeftChild->Right->Parent = Parent; // 

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == nullptr)
		Root = LeftChild;
	else
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = LeftChild;
		else
			Parent->Parent->Right = LeftChild;
	}

	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}

void RBT_RotateLeft(RBTNode*& Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
		RightChild->Left->Parent = Parent;
	
	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == nullptr)
		Root = RightChild;
	else
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = RightChild;
		else
			Parent->Parent->Right = RightChild;
	}

	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

RBTNode* RBT_RemoveNode(RBTNode*& Root, ElementType Data)
{
	RBTNode* Removed = nullptr;
	RBTNode* Successor = nullptr;
	RBTNode* Target = RBT_SearchNode(Root, Data);

	if (Target == nullptr)
		return nullptr;

	if (Target->Left == Nil || Target->Right == Nil)
		Removed = Target;
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
		Successor = Removed->Left;
	else
		Successor = Removed->Right;

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == nullptr)
		Root = Successor;
	else
	{
		if (Removed == Removed->Parent->Left)
			Removed->Parent->Left = Successor;
		else
			Removed->Parent->Right = Successor;
	}

	if (Removed->color == Color::BLACK)
		RBT_RebuildAfterRemove(Root, Successor);

	return Removed;
}

void RBT_RebuildAfterRemove(RBTNode*& Root, RBTNode* Successor)
{
	RBTNode* Sibling = nullptr;

	while (Successor->Parent != nullptr && Successor->color == Color::BLACK)
	{
		if (Successor == Successor->Parent->Left)
		{
			Sibling = Successor->Parent->Right;

			if (Sibling->color == Color::RED)
			{
				Sibling->color = Color::BLACK;
				Successor->Parent->color = Color::RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Left->color == Color::BLACK && Sibling->Right->color == Color::BLACK)
				{
					Sibling->color = Color::RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Left->color == Color::RED)
					{
						Sibling->Left->color = Color::BLACK;
						Sibling->color = Color::RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					Sibling->color = Successor->Parent->color;
					Successor->Parent->color = Color::BLACK;
					Sibling->Right->color = Color::BLACK;
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = Root;
				}
			}
		}
		else
		{
			Sibling = Successor->Parent->Left;

			if (Sibling->color == Color::RED)
			{
				Sibling->color = Color::BLACK;
				Successor->Parent->color = Color::RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Right->color == Color::BLACK && Sibling->Left->color == Color::BLACK)
				{
					Sibling->color = Color::RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Right->color == Color::RED)
					{
						Sibling->Right->color = Color::BLACK;
						Sibling->color = Color::RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					Sibling->color = Successor->Parent->color;
					Successor->Parent->color = Color::BLACK;
					Sibling->Left->color = Color::BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = Root;
				}
			}
		}
	}

	Successor->color = Color::BLACK;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	char c = 'X';
	int v = -1;
	string cnt;

	if (Node == nullptr || Node == Nil)
		return;

	if (Node->color == Color::BLACK)
		BlackCount++;

	if (Node->Parent != nullptr)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
			c = 'L';
		else
			c = 'R';
	}

	if (Node->Left == Nil && Node->Right == Nil)
		cnt = "--------- " + to_string(BlackCount);
	else
		cnt = "";

	for (int i = 0; i < Depth; ++i)
		cout << "   ";

	cout << Node->Data << " " << ((Node->color == Color::RED) ? "RED" : "BLACK") << " [" << c << ", " << v << "] " << cnt << "\n";

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}