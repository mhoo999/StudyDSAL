#include "LLS.h"

using namespace std;

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack(Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));

	Count = LLS_GetSize(Stack);
	cout << "Size : " << Count << ", Top : " << LLS_Top(Stack)->Data << endl;

	for (int i = 0; i < Count; ++i)
	{
		if (LLS_IsEmpty(Stack))
			break;

		Popped = LLS_Pop(Stack);

		cout << "Popped : " << Popped->Data << endl;

		LLS_DestroyNode(Popped);

		if (!LLS_IsEmpty(Stack))
		{
			cout << "Current Top : " << LLS_Top(Stack)->Data << endl;
		}
		else
		{
			cout << "Stack is empty\n";
		}
	}

	LLS_DestroyStack(Stack);

	return 0;
}