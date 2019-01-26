#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
    node *prev;
}*nodeptr;

nodeptr newNode = new node;
node *head = NULL;
node *tail = NULL;

nodeptr createNode(int data){
	nodeptr newNode = new node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

void addData(int data){
    nodeptr newNode=createNode(data);
    if(head == NULL){
    	head = newNode;
    	tail = head;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail= tail->next;
	}
}

void display(){
	nodeptr ptr = head;
	cout<<" The list is: ";
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}cout<<endl;
}

void search(int selement){
	nodeptr ptr = head;
	while(ptr != NULL){
		if(ptr->data == selement){
			cout<<" "<<selement<<" Founded !!"<<endl;
			return;
		}
		ptr = ptr->next;
	}
	if(ptr == NULL){
		cout<<" "<<selement<<" Not found!!"<<endl;
	}
}

void insertDataBegin(int idb){
	nodeptr newNode=createNode(idb);
	newNode->data = idb;
	newNode->next = head;
	head = newNode;
}
int main()
{
    int data,n,selement,idb;
    cout<<" Enter elements number: ";
    cin>>n;
    cout<<" Enter the elements: ";
    for(int i=0 ; i<n ; i++){
        cin>>data;
        addData(data);
    }
    display();
    cout<<" Do u wanna search: ";
    cin>>selement;
    search(selement);
    cout<<" U wanna insert Begin: ";
    cin>>idb;
    insertDataBegin(idb);
    display();
}
