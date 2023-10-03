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
	while (X != Root && X->Parent->color == Color::RED) // X�� Root�� �ƴϰ� X�� Parent�� Color�� RED�� ���
	{
		if (X->Parent == X->Parent->Parent->Left) // X�� Parent�� �Ҿƹ��� ����� Left �ڽ��� ���
		{
			RBTNode* Uncle = X->Parent->Parent->Right; // ���� ��� ����
			if (Uncle->color == Color::RED) // ���� ��嵵 RED�� ���(Parent, Uncle == RED)
			{
				X->Parent->color = Color::BLACK;  // X�� �θ� BLACK
				Uncle->color = Color::BLACK; // ������ BLACK
				X->Parent->Parent->color = Color::RED; // �Ҿƹ����� RED

				X = X->Parent->Parent; // X = �Ҿƹ��� ���
			}
			else // ���� ��尡 BLACK�� ���
			{
				if (X == X->Parent->Right) // X�� �θ��� Right ����� ���
				{
					X = X->Parent; // X = �θ� ���
					RBT_RotateLeft(Root, X); // �θ� ��带 �߽����� ��ȸ��
				}

				X->Parent->color = Color::BLACK; // X�� �÷� BLACK
				X->Parent->Parent->color = Color::RED; // X �Ҿƹ��� �÷� RED

				RBT_RotateRight(Root, X->Parent->Parent); // X �Ҿƹ��� �߽����� ��ȸ��
			}
		}
		else // X�� Parent�� �Ҿƹ��� ����� Right �ڽ��� ���(�� ���̽��� Left<->Right ��ü ����)
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
	RBTNode* LeftChild = Parent->Left; // Left Child ��带 Parent->Left ������ �ʱ�ȭ

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