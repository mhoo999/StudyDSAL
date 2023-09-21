#pragma once

// 링크드 리스트의 노드 표현

typedef int ElementType; // 필요한 자료형 지정

//struct Node
//{
//	ElementType Data; // 데이터
//	struct Node* NextNode; // 다음 노드
//};

typedef struct Node // typedef 예약어를 사용하여 간편하게 인스턴스 생성
{
	ElementType Data;
	struct Node* NextNode;
} Node;