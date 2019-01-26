#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}*nodeptr;

nodeptr newNode = new node;
node *head = NULL;
node *curr = NULL;

void push(int data){
	nodeptr newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	else{
		curr->next = newNode;
	}
	curr = newNode;
}

int pop(){
	nodeptr ptr = head,dptr;
	while(ptr->next->next != NULL){
		ptr = ptr->next;
	}
	dptr = ptr->next;
	ptr->next = NULL;
	return dptr->data;	
}

void display(){
	nodeptr ptr = head;
	cout<<" The stack is: ";
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main()
{
	int n,data;
	cout<<" Enter the elements number: ";
	cin>>n;
	if(n !=NULL){
		cout<<" Enter the elemnts: ";
		for(int i=0;i<n;i++){
			cin>>data;
			push(data);
		}
		display();
		cout<<" Pop value is: "<<pop()<<endl;
		cout<<" Pop value is: "<<pop()<<endl;
		cout<<" Pop value is: "<<pop()<<endl;
		display();
	}
}
