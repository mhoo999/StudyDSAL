#pragma once

typedef char ElementType;

class LCRSNode
{
public:
	LCRSNode* LeftChild;
	LCRSNode* RightSibling;

	ElementType Data;

	static LCRSNode* CreateNode(ElementType NewData);
	static void DestroyNode(LCRSNode* Node);
	static void DestroyTree(LCRSNode* Root);

	static void AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);
	static void printTree(LCRSNode* Node, int Depth);
};