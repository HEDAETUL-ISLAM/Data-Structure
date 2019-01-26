#include<iostream>
using namespace std;

int main()
{
    int temp,n,arr[100];
    cout<<"enter the element of numbers: ";
    cin>>n;
    cout<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int j=0;j<n;j++){
        cout<<arr[j];
    }
}
