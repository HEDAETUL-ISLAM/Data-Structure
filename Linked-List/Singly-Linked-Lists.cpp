#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}*nodeptr;

nodeptr newNode = new node;
node *head=NULL;
node *curr=NULL;

int addData(int data){
	nodeptr newNode = new node;
		newNode->data=data;
		newNode->next=NULL;
		if(head == NULL){
			head = newNode;
		}
		else{
			curr->next = newNode;
		}
		curr = newNode;
}

void display(){
	nodeptr ptr=head;
	cout<<"the list is: ";
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void search(int selement){
	nodeptr ptr=head;
	while(ptr!=NULL){
		if(ptr->data == selement){
			cout<<selement<<" found"<<endl;
			return;
		}
		ptr=ptr->next;	
	}
	if(ptr==NULL)
		cout<<selement<<" not found"<<endl;
}

void insertDataBegin(int idb){
	nodeptr newNode = new node;
	newNode->data=idb;
	newNode->next=head;
	head=newNode;
}

void insertDataMid(int position,int idm){
	nodeptr newNode = new node;
	newNode->data=idm;
	nodeptr ptr=head;
	int i=0;
	while(i<position-1){
		ptr=ptr->next;
		i++;
	}
	
	nodeptr temp=ptr->next;
	ptr->next=newNode;
	newNode->next=temp;
	
}

void insertDataLast(int idl){
	nodeptr newNode = new node;
	newNode->data=idl;
	newNode->next=NULL;
	if(head == NULL){
		head=newNode;
	}
	else{
		curr=head;
		while(curr->next != NULL){
			curr=curr->next;
		}
		curr->next=newNode;
	}
}

void firstNodeDelete(){
	nodeptr ptr=head;
	head=ptr->next;
	delete(ptr);
}

void midNodeDelete(int mnd){
	nodeptr ptr = head,dptr;
	while(ptr->next->data != mnd && ptr->next != NULL){
		ptr=ptr->next;
	}
	dptr=ptr->next;
	ptr->next=ptr->next->next;
	delete(dptr);
}

void lastNodeDelete(){
	nodeptr ptr=head,dptr;
	while(ptr->next->next != NULL){
		ptr=ptr->next;
	}
	dptr=ptr->next;
	ptr->next=NULL;
	delete(dptr);
}
int main()
{
	int n,data,selement,idb,idl,position,idm,mnd;
	cout<<"how much: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data;
		addData(data);
	}
	display();
	cout<<"which elements u wanna search: ";
	cin>>selement;
	search(selement);
	cout<<"u wanna insert data began : ";
	cin>>idb;
	insertDataBegin(idb);
	display();
	cout<<"u wanna insert data middle: ";
	cin>>idm;
	cout<<"which position: ";
	cin>>position;
	insertDataMid(position,idm);
	display();
	cout<<"u wanna insert data last : ";
	cin>>idl;
	insertDataLast(idl);
	display();
	cout<<"after first node delete ";
	firstNodeDelete();
	display();
	cout<<"which element u wanna delete: ";
	cin>>mnd;
	cout<<"after mid node delete: ";
	midNodeDelete(mnd);
	display();
	cout<<"after last node delete: ";
	lastNodeDelete();
	display();
}
