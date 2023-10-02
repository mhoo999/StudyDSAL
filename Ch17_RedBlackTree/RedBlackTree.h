#pragma once

#include <iostream>
#include <string>

using namespace std;
using ElementType = int;
enum class Color { RED, BLACK};

class RBTNode
{
public:
	RBTNode* Parent;
	RBTNode* Left;
	RBTNode* Right;

	Color color;

	ElementType Data;
};


RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestroyNode(RBTNode* Node);
void RBT_DestroyTree(RBTNode* Tree);

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);
RBTNode* RBT_SearchMinNode(RBTNode* Tree);

void RBT_InsertNode(RBTNode*& Tree, RBTNode* NewNode);
void RBT_InsertNodeHelper(RBTNode*& Tree, RBTNode* NewNode);
void RBT_RebuildAfterInsert(RBTNode*& Tree, RBTNode* NewNode);

void RBT_RotateRight(RBTNode*& Root, RBTNode* Parent);
void RBT_RotateLeft(RBTNode*& Root, RBTNode* Parent);

RBTNode* RBT_RemoveNode(RBTNode*& Root, ElementType Data);
void RBT_RebuildAfterRemove(RBTNode*& Root, RBTNode* Successor);

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);