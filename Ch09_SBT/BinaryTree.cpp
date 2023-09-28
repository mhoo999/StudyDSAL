#include <iostream>
#include "BinaryTree.h"

using namespace std;

SBTNode* SBTNode::SBT_CreateNode(ElemetType NewData)
{
	SBTNode* NewNode = new SBTNode;

	NewNode->LeftNode = nullptr;
	NewNode->RightNode = nullptr;
	NewNode->Data = NewData;

	return NewNode;
}

void SBTNode::SBT_DestroyNode(SBTNode* Node)
{
	delete Node;
}

void SBTNode::SBT_DestroyTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	SBT_DestroyTree(Node->LeftNode);
	SBT_DestroyTree(Node->RightNode);
	SBT_DestroyNode(Node);
}

void SBTNode::SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	cout << Node->Data;

	SBT_PreorderPrintTree(Node->LeftNode);
	SBT_PreorderPrintTree(Node->RightNode);
}

void SBTNode::SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	SBT_InorderPrintTree(Node->LeftNode);
	cout << Node->Data;
	SBT_InorderPrintTree(Node->RightNode);
}

void SBTNode::SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	SBT_PostorderPrintTree(Node->LeftNode);
	SBT_PostorderPrintTree(Node->RightNode);
	cout << Node->Data;
}
