#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

int main() {
    string InfixExpression;
    string PostfixExpression;

    double Result = 0.0;

    cout << "Enter Infix Expression: ";
    cin >> InfixExpression;

    GetPostfix(InfixExpression, PostfixExpression);

    cout << "Infix: " << InfixExpression << "\nPostfix: " << PostfixExpression << endl;

    Result = Calculate(PostfixExpression);

    cout << "Calculation Result: " << Result;

    return 0;
}