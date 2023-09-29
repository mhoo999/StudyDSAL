#include <iostream>

using namespace std;

typedef char ElementType;

class ETNode
{
public:
	ETNode* Left;
	ETNode* Right;
	ElementType Data;
};

ETNode* CreateNode(ElementType NewData);
void DestroyNode(ETNode* Node);
void DestroyTree(ETNode* Root);

void PreorderPrintTree(ETNode* Node);
void InorderPrintTree(ETNode* Node);
void PostorderPrintTree(ETNode* Node);

void BuildExpressionTree(char* PostfixExpression, ETNode*& Node);
double Evaluate(ETNode* Tree);