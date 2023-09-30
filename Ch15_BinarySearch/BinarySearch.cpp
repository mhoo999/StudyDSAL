#include <iostream>
#include "Point.h"

using namespace std;

Point* BinarySearch(Point PointList[], int Size, double Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		if (Target == PointList[Mid].Point)
			return &(PointList[Mid]);
		else if (Target > PointList[Mid].Point)
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	return nullptr;
}

int ComparePoint(const void* _elem1, const void* _elem2)
{
	Point* elem1 = (Point*)_elem1;
	Point* elem2 = (Point*)_elem2;

	if (elem1->Point > elem2->Point)
		return 1;
	else if (elem1->Point < elem2->Point)
		return -1;
	else
		return 0;
}

int main()
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	Point* found = nullptr;

	qsort((void*)DataSet, Length, sizeof(Point), ComparePoint); // 구매 포인트 오름차순 정렬

	found = BinarySearch(DataSet, Length, 671.78);

	cout << "found... ID: " << found->Id << ", Point: " << found->Point;

	return 0;
}