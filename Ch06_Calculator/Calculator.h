#pragma once

#include <string>

using namespace std;

enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/', SPACE = ' ', OPERAND
};

// ���� ǥ����� ���� ǥ������� �ٲٴ� �Լ�
void GetPostfix(const string &InfixExpression, string &PrefixExpression, int* Type);

// ���� ǥ����� ����ϴ� �Լ�
double Calculate(const string PrefixExpression);

