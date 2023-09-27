#include "Calculator.h"
#include "Ch06_LLS.h"

void GetPostfix(const string& InfixExpression, string& PrefixExpression, int* Type)
{
	string Number = { 0,1,2,3,4,5,6,7,8,9,'.'};

	LinkedListStack* Stack;
	
	LLS_CreateStack(&Stack);

	for (int i = 0; i < sizeof(InfixExpression); ++i)
	{
		if (InfixExpression[i] >= 0 && InfixExpression[i] <= 9)
		{
			Node* NewNode = LLS_CreateNode(&InfixExpression[i]);
			LLS_Push(Stack, NewNode);
		}
		else if (InfixExpression[i] == Type)
	}

}

double Calculate(const string PrefixExpression)
{
	return 0.0;
}
