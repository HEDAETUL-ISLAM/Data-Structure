#include<iostream>
using namespace std;

int top=-1;
int stack[5];
int size =5;

int push(int data){
	if(top>=size-1){
		cout<<"STACK IS FULL."<<endl;
	}
	else{
		top++;
		stack[top]=data;
		cout<<stack[top]<<endl;
	}
}
int pop(){
	if(top<0){
		cout<<"STACK IS EMPTY."<<endl;
	}
	else{
		int data=stack[top];
		top--;
		return data;
	}
}
int traverse(){
	for(int i=top;i>=0;i--){
		cout<<" "<<stack[i];
	}
}
int Top(){
	return top;
}

int main()
{
	push(5);
	cout<<"top is: "<<Top()<<endl;
	push(6);
	cout<<"top is: "<<Top()<<endl;
	push(7);
	cout<<"top is: "<<Top()<<endl;
	push(8);
	cout<<"top is: "<<Top()<<endl;
	push(9);
	cout<<"top is: "<<Top()<<endl;
	push(10);
	cout<<"traverse is: "<<endl;
	traverse();
	cout<<endl<<endl<<"from here pop will counting"<<endl<<endl;
	cout<<"pop is: "<<pop()<<endl;
	cout<<"top is: "<<Top()<<endl;
	cout<<"pop is: "<<pop()<<endl;
	cout<<"top is: "<<Top()<<endl;
	cout<<"pop is: "<<pop()<<endl;
	cout<<"top is: "<<Top()<<endl;
	cout<<"pop is: "<<pop()<<endl;
	cout<<"top is: "<<Top()<<endl;
	cout<<"pop is: "<<pop()<<endl;
	cout<<"top is: "<<Top()<<endl;
}
