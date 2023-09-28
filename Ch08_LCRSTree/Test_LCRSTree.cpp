#include "LCRSTree.h"

int main() {
	// 노드 생성
	LCRSNode* Root = LCRSNode::CreateNode('A');
	LCRSNode* B = LCRSNode::CreateNode('B');
	LCRSNode* C = LCRSNode::CreateNode('C');
	LCRSNode* D = LCRSNode::CreateNode('D');
	LCRSNode* E = LCRSNode::CreateNode('E');
	LCRSNode* F = LCRSNode::CreateNode('F');
	LCRSNode* G = LCRSNode::CreateNode('G');
	LCRSNode* H = LCRSNode::CreateNode('H');
	LCRSNode* I = LCRSNode::CreateNode('I');
	LCRSNode* J = LCRSNode::CreateNode('J');
	LCRSNode* K = LCRSNode::CreateNode('K');

	// 트리에 노드 추가
	LCRSNode::AddChildNode(Root, B);
		LCRSNode::AddChildNode(B, C);
		LCRSNode::AddChildNode(B, D);
			LCRSNode::AddChildNode(D, E);
			LCRSNode::AddChildNode(D, F);

	LCRSNode::AddChildNode(Root, G);
		LCRSNode::AddChildNode(G, H);

	LCRSNode::AddChildNode(Root, I);
		LCRSNode::AddChildNode(I, J);
			LCRSNode::AddChildNode(J, K);	

	// 트리 출력
	LCRSNode::printTree(Root, 0);

	// 트리 소멸
	LCRSNode::DestroyTree(Root);

	return 0;
}