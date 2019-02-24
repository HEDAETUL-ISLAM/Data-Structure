
// #include<iostream>
// #include<stack>
// #include<string>
#include<bits/stdc++.h>
using namespace std;



bool Term(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    if(c == '.'){
        return true;
    }
    // if(c == '^'){
    //     return true;
    // }
    return false;
}

bool IsOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ){
        return true;
    }
    return false;
}

int IsRigthAssociative(char c){             //check it right associative or not
    if(c == '^' ){
        return false;
    }
    return true;

}

int GetOperatorWeight(char operators){               //for precedence lavel set
    int weight = -1;
    switch(operators){
        case '+':
        case '-':
            weight=1;

        case '*':
        case '/':
            weight=2;

        case '^':
            weight=3;

    }
    return weight;
}


int HasHigherPrecedence(char operatorOne, char operatorTwo){
    int operatorOneWeight = GetOperatorWeight(operatorOne);
    int operatorTwoWeight = GetOperatorWeight(operatorTwo);

    // if equal precedence return true if they left associative.return false if they right associative. if left associative then left one give priority
    if(operatorOneWeight == operatorTwoWeight){
        if(IsRigthAssociative(operatorOne) ){
            return false;
        }
        else{
            return true;
        }
    }
    else if(operatorOneWeight > operatorTwoWeight){
        return true;
    }
    return false;
}

string Postfix(string expression){              //solve postfix expression

    stack<char> Stack;
    string postfix="";                          //initial as a empty
    for(int i=0;i<expression.length();i++){
        if(expression[i] ==' ' || expression[i] == ','){                //if delimeter then move next
            continue;
        }
        else if(IsOperator(expression[i])){
            while(!Stack.empty() && Stack.top() != '(' && HasHigherPrecedence(Stack.top(), expression[i])){
                postfix = postfix+Stack.top();
                Stack.pop();
            }
            Stack.push(expression[i]);
        }
        else if(Term(expression[i])){               //if the char is an operand or term
            postfix = postfix+expression[i];
        }
        else if(expression[i] == '('){
            Stack.push(expression[i]);
        }
        else if(expression[i] == ')'){
            while(!Stack.empty() && Stack.top() != '('){
                postfix = postfix+Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
    }
    while(!Stack.empty()){
        postfix = postfix+Stack.top();
        Stack.pop();
    }
    return postfix;
}


int main()
{
    string expression;
    cout<<"enter expression in enfix order: ";
    getline(cin,expression);
    cout<<"Postfix : "<<Postfix(expression);
}
