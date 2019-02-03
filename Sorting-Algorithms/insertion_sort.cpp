#include<iostream>
using namespace std;

int main()
{    int temp,n,arr[100],j,i;
    cout<<"enter the numbers of elements: ";
    cin>>n;
    cout<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        for(;temp<arr[j]&&j>=0;j--){
            arr[j+1]=arr[j];
        }/*
        while(temp<arr[j]  && j>=0){
            arr[j+1]=arr[j];
            j--;
        }*/
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
