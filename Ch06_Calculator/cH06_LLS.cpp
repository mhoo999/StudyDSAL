#include "Ch06_LLS.h"

void LLS_CreateStack(LinkedListStack*& Stack)
{
    Stack = new LinkedListStack();

    Stack->List = nullptr;
    Stack->Top = nullptr;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
    while (!LLS_IsEmpty(Stack))
    {
        LLS_DestroyNode(LLS_Pop(Stack));
    }

    delete Stack;
}

Node* LLS_CreateNode(string Data)
{
    Node* newNode = new Node();
    //newNode->Data = new char[std::strlen(Data) + 1];

    newNode->Data = Data;
    return newNode;
}

void LLS_DestroyNode(Node* _Node)
{
    delete _Node;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
    NewNode->NextNode = Stack->Top;
    Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
    if (!Stack->Top)
        return nullptr;

    Node* poppedNode = Stack->Top;
    Stack->Top = poppedNode->NextNode;
    poppedNode->NextNode = nullptr;

    return poppedNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
    int count = 0;
    Node* currentNode = Stack->Top;
    while (currentNode)
    {
        count++;
        currentNode = currentNode->NextNode;
    }
    return count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
    return Stack->Top == nullptr;
}