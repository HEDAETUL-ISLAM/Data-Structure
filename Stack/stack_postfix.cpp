#include <bits/stdc++.h>
using namespace std;

int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int main()
{
	string expression;
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output = "<<result<<"\n";
}

int EvaluatePostfix(string expression){ // evaluate Postfix expression and return output

	stack<int> S;// Declaring a Stack

	for(int i = 0;i< expression.length();i++){

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(IsOperator(expression[i])){
			// Pop two operands.
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			// Perform operation
			int result = PerformOperation(expression[i], operand1, operand2);
			//Push back result of operation on stack.
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int operand = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])){
				operand = (operand*10) + (expression[i] - '0');
				i++;
			}
			i--;

			// Push operand on stack.
			S.push(operand);
		}
	}
	return S.top();
}

bool IsNumericDigit(char C){//verify whether a character is numeric digit.
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator(char C){// verify whether a character is operator symbol or not
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

int PerformOperation(char operation, int operand1, int operand2){// perform an operation and return output
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}
