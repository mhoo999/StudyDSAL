#pragma once

typedef char ElemetType;

class SBTNode
{
public:
	SBTNode* LeftNode;
	SBTNode* RightNode;
	ElemetType Data;

	static SBTNode* SBT_CreateNode(ElemetType NewData);
	static void SBT_DestroyNode(SBTNode* Node);
	static void SBT_DestroyTree(SBTNode* Node);

	static void SBT_PreorderPrintTree(SBTNode* Node);
	static void SBT_InorderPrintTree(SBTNode* Node);
	static void SBT_PostorderPrintTree(SBTNode* Node);
};