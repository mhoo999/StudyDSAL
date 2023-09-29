#include "ExpressionTree.h"

ETNode* CreateNode(ElementType NewData)
{
	ETNode* NewNode = new ETNode;

	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	NewNode->Data = NewData;

	return NewNode;
}

void DestroyNode(ETNode* Node)
{
	delete Node;
}

void DestroyTree(ETNode* Root)
{
	if (Root == nullptr)
		return;

	DestroyTree(Root->Left);
	DestroyTree(Root->Right);

	DestroyNode(Root);
}

void PreorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;

	cout << Node->Data;
	PreorderPrintTree(Node->Left);
	PreorderPrintTree(Node->Right);
}

void InorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;

	cout << '(';
	InorderPrintTree(Node->Left);
	cout << Node->Data;
	InorderPrintTree(Node->Right);
	cout << ')';
}

void PostorderPrintTree(ETNode* Node)
{
	if (Node == nullptr)
		return;

	PostorderPrintTree(Node->Left);
	PostorderPrintTree(Node->Right);
	cout << Node->Data;
}

void BuildExpressionTree(char* PostfixExpression, ETNode*& Node)
{
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token)
	{
	case '+': case '-': case '*': case '/':
		Node = CreateNode(Token);
		BuildExpressionTree(PostfixExpression, Node->Right);
		BuildExpressionTree(PostfixExpression, Node->Left);
		break;

	default:
		Node = CreateNode(Token);
		break;
	}
}

double Evaluate(ETNode* Tree)
{
	char Temp[2]; // 피연산자의 값이 한 자리이기 떄문에 2개의 요소가 필요('\0')

	double Left = 0;
	double Right = 0;
	double Result = 0;

	if (Tree == nullptr)
		return 0;

	switch (Tree->Data)
	{
	case '+': case '-': case '*': case '/':
		Left = Evaluate(Tree->Left);
		Right = Evaluate(Tree->Right);

			 if (Tree->Data == '+') Result = Left + Right;
		else if (Tree->Data == '-') Result = Left - Right;
		else if (Tree->Data == '*') Result = Left * Right;
		else if (Tree->Data == '/') Result = Left / Right;

		break;

	default:
		memset(Temp, 0, sizeof(Temp)); // 초기화 왜 하는 거?
		Temp[0] = Tree->Data; // 값 저장
		Result = atof(Temp); // float 으로 값 반환
		break;
	}

	return Result;
}