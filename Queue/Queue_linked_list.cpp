#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data){
	node *newNode = new node;
	newNode->data=data;
	newNode->next=NULL;
	if(front == NULL && rear == NULL){
		front=rear=newNode;
		return ;
	}
	else{
		rear->next=newNode;
	}
	rear=newNode;
}

int dequeue(){
	node *dptr = front;
	if(front == NULL){
		cout<<"queue is empty";
	}
	front=front->next;
	if(front==NULL){
		rear=NULL;
	}
	return dptr->data;
}



void print(){
	node *temp=front;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	int n,data;
	cout<<"enter the size: ";
	cin>>n;
	if(n!=NULL){
		cout<<"enter teh data: ";
		for(int i=0;i<n;i++){
			cin>>data;
			enqueue(data);
		}
		print();
		cout<<"dequeue value is "<<dequeue()<<endl;
		cout<<"dequeue value is "<<dequeue()<<endl;
		cout<<"dequeue value is "<<dequeue()<<endl;
		print();
	}
	
}
