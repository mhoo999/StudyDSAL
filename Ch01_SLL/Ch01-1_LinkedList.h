#pragma once

// ��ũ�� ����Ʈ�� ��� ǥ��

typedef int ElementType; // �ʿ��� �ڷ��� ����

//struct Node
//{
//	ElementType Data; // ������
//	struct Node* NextNode; // ���� ���
//};

typedef struct Node // typedef ���� ����Ͽ� �����ϰ� �ν��Ͻ� ����
{
	ElementType Data;
	struct Node* NextNode;
} Node;