#include "ExpressionTree.h"

int main(void)
{
	ETNode* Root = nullptr;

	char PostfixExpression[20] = "71*52-/";
	BuildExpressionTree(PostfixExpression, Root);
	
	// 트리 출력
	cout << "Preorder...\n";
	PreorderPrintTree(Root);
	cout << "\n\n";

	cout << "Inorder...\n";
	InorderPrintTree(Root);
	cout << "\n\n";

	cout << "Postorder...\n";
	PostorderPrintTree(Root);
	cout << "\n\n";

	cout << "Evaulation Result : " << Evaluate(Root);

	// 트리 소멸
	DestroyTree(Root);

	return 0;
}