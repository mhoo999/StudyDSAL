
typedef int ElementType;

typedef struct Node
{
	ElementType Data;
	struct Node* NextNode;
	struct Node* PrevNode;
} Node;