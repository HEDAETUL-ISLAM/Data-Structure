# Searching-Algorithm

linear search

#include<iostream>
using namespace std;

int main()
{
	int n, arr[100], selement,count=0;
	cout<<"enter the size of the file: ";
	cin>>n;
	cout<<"enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"enter the searched element: ";
	cin>>selement;
	for(int i=0;i<n;i++){
		if(selement == arr[i]){
			count=1;
		}
	}
	if(count==0){
		cout<<"not found :)"<<endl;
	}
	else{
		cout<<"yes found :("<<endl;
	}
}
