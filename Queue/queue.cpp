#include<iostream>
using namespace std;

int rear=-1;
int front=-1;;
int size=5;
int queue[5];
int nOfElements=0;

int enqueue(int x){
	if(rear>=size-1){
		cout<<"queue is full"<<endl;
	}
	else{
		rear++;
		queue[rear]=x;
		if(front==-1){
			front++;	
		}
		nOfElements++;
		cout<<"enqueue is: "<<queue[rear]<<endl;
	}
}
int dequeue(){
	if(front==-1 || front>rear){
		cout<<"queue is empty"<<endl;
	}
	else{
		int x=queue[front];
		front++;
		return x;
		//nOfElements--;
	}
	nOfElements--;
}
int main()
{
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	
	cout<<"no of elements: "<<nOfElements<<endl;
	cout<<endl<<"dequeue is count now."<<endl<<endl;
	
	
	cout<<"dequeue is: "<<dequeue()<<endl;
	cout<<"dequeue is: "<<dequeue()<<endl;
	cout<<"dequeue is: "<<dequeue()<<endl;
	cout<<"dequeue is: "<<dequeue()<<endl;
	cout<<"dequeue is: "<<dequeue()<<endl;
	cout<<"no of elements: "<<nOfElements<<endl;

}
