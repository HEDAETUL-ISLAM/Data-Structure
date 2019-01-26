# Searching-Algorithm

binary search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int L, int n, int value){
	
	while(L<=n){
		int m=L+(n-L)/2;
		if(arr[m] == value){
			return m;
		}
		if(arr[m] < value){
			L=m+1;
		}
		else{
			n=m-1;
		}
	}	
	return -1;
}
//in binary search data need to on shorted list
int sorting(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				swap(arr[i],arr[j]);
			}
		}
	}
}

int main()
{
	int n,value,arr[100];
	cout<<" Enter the elements number: ";
	cin>>n;
	cout<<" Enter the shorted array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sorting(arr,n);
	cout<<" Enter your search element: ";
	cin>>value;
	int result=binarySearch(arr,0,n,value);
	if(result == -1){
		cout<<" not found :("<<endl;
	}
	else{
		cout<<" yes found :)"<<endl;
	}
}
