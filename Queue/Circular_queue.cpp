#include<iostream>
using namespace std;

int front=0;
int rear=0;
const int size=6;
int queue[size];

int enqueue(int x){
	int next_rear=(rear+1)%size;
	cout<<" next rear: "<<next_rear<<endl;
	if(next_rear == front){
		cout<<" queue is full. "<<endl;
	}
	else{
		queue[rear]=x;
		cout<<" rear: "<<rear<<endl;
		rear=next_rear;
	}
}
int dequeue(){
	if(front == rear){
		cout<<" queue is empty."<<endl;
	}
	else{
		front=(front+1)%size;
		cout<<" front: "<<front<<endl;
	}
	return front;
}
void display(){
cout<<" the queue elements are: ";
	for(int i=front;i!=rear;i=(i+1)%size){
		cout<<queue[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	enqueue(3);
	display();
	enqueue(4);
	display();
	enqueue(7);
	display();
	enqueue(2);
	display();
	enqueue(5);
	display();
	
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	cout<<"dequeue is: "<<dequeue()<<endl;
	display();
	enqueue(111);
	display(); 
	

}
