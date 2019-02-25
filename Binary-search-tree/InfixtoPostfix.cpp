#include<iostream>
using namespace std;

char input[]="(A*(5+(C/7)))";
char *lookAhed=input;

void factor();
void expressionPlusMinus();
void match(char c);
void Expression();
void term();
void expressionMulDiv();


int main()
{
	Expression();
}

void Expression(){
	term();
	expressionPlusMinus();
}

void expressionPlusMinus(){
	if(*lookAhed=='+'){
		match('+');
		term();
		cout<<'+';
		expressionPlusMinus();
	}
	else if(*lookAhed=='-'){
		match('-');
		term();
		cout<<'-';
		expressionPlusMinus();
	}
}

void term(){
	factor();
	expressionMulDiv();
}

void expressionMulDiv(){
	if(*lookAhed=='*'){
		match('*');
		factor();
		cout<<'*';
		expressionMulDiv();
	}
	if(*lookAhed=='/'){
		match('/');
		factor();
		cout<<'/';
		expressionMulDiv();
	}
}

void factor(){
	if(isdigit(*lookAhed)){
		cout<<*lookAhed;
		lookAhed++;
	}
	else if(isalpha(*lookAhed)){
		cout<<*lookAhed;
		lookAhed++;
	}
	else if(*lookAhed=='('){
		match('(');
		Expression();
		match(')');
	}
	
}

void match(char c){
	if(*lookAhed==c){
		lookAhed++;
	}
}
