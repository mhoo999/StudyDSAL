#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(void) {
	
	// 노드 생성
	SBTNode* A = SBTNode::SBT_CreateNode('A');
	SBTNode* B = SBTNode::SBT_CreateNode('B');
	SBTNode* C = SBTNode::SBT_CreateNode('C');
	SBTNode* D = SBTNode::SBT_CreateNode('D');
	SBTNode* E = SBTNode::SBT_CreateNode('E');
	SBTNode* F = SBTNode::SBT_CreateNode('F');
	SBTNode* G = SBTNode::SBT_CreateNode('G');

	// 트리에 노드 추가
	A->LeftNode = B;
	B->LeftNode = C;
	B->RightNode = D;

	A->RightNode = E;
	E->LeftNode = F;
	E->RightNode = G;

	// 트리 출력
	cout << "Preorder...\n";
	SBTNode::SBT_PreorderPrintTree(A);
	cout << "\n\n";

	cout << "Inorder...\n";
	SBTNode::SBT_InorderPrintTree(A);
	cout << "\n\n";

	cout << "postorder...\n";
	SBTNode::SBT_PostorderPrintTree(A);
	cout << "\n\n";

	// 트리 소멸
	SBTNode::SBT_DestroyTree(A);

	return 0;
}