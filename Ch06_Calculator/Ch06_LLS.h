#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Node
{
public:
    string Data;
    //char* Data;
    Node* NextNode = nullptr;  // Member initialization in C++11
    ~Node() {
        //delete[] Data;
    }
};

class LinkedListStack
{
public:
    Node* List = nullptr;  // Member initialization in C++11
    Node* Top = nullptr;   // Member initialization in C++11
    ~LinkedListStack() {
        Node* currentNode = List;
        while (currentNode) {
            Node* nextNode = currentNode->NextNode;
            delete currentNode;
            currentNode = nextNode;
        }
    }
};

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(string Data);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);