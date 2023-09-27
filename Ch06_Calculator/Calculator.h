#pragma once

#include <string>

using namespace std;

enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/', SPACE = ' ', OPERAND
};

// 중위 표기식을 후위 표기식으로 바꾸는 함수
void GetPostfix(const string &InfixExpression, string &PrefixExpression, int* Type);

// 후위 표기식을 계산하는 함수
double Calculate(const string PrefixExpression);

