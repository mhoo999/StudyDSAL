#include <iostream>
#include "LCRSTree.h"

using namespace std;

LCRSNode* LCRSNode::CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = new LCRSNode;

	NewNode->LeftChild = nullptr;
	NewNode->RightSibling = nullptr;
	NewNode->Data = NewData;

	return NewNode;
}

void LCRSNode::DestroyNode(LCRSNode* Node)
{
	delete Node;
}

void LCRSNode::DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != nullptr)
		LCRSNode::DestroyTree(Root->RightSibling);
	if (Root->LeftChild != nullptr)
		LCRSNode::DestroyTree(Root->LeftChild);

	Root->LeftChild = nullptr;
	Root->RightSibling = nullptr;

	LCRSNode::DestroyNode(Root);
}

void LCRSNode::AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode)
{
	if (ParentNode->LeftChild == nullptr)
		ParentNode->LeftChild = ChildNode;
	else
	{
		LCRSNode* TempNode = ParentNode->LeftChild;
		while (TempNode->RightSibling != nullptr)
		{
			TempNode = TempNode->RightSibling;
		}
		TempNode->RightSibling = ChildNode;
	}
}

void LCRSNode::printTree(LCRSNode* Node, int Depth)
{
	// �鿩����
	for (int i = 0; i < Depth + 1; ++i)
		cout << "   "; // ���� 3ĭ
	
	if (Depth > 0) // �ڽ� ��� ���� ǥ��
		cout << "+---";

	// ��� ������ ���
	cout << Node->Data << endl;

	if (Node->LeftChild != nullptr)
		LCRSNode::printTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != nullptr)
		LCRSNode::printTree(Node->RightSibling, Depth);
}