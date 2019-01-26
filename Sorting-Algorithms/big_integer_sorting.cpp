#include<bits/stdc++.h>
using namespace std;

bool cmp(const string &left, const string &right){
	if(left.size() == right.size()){
		return left<right;
	}
	else{
		return left.size()<right.size();
	}
}

void sortBigIntegers(string arr[], int n){
	vector <string> sortArr(arr, arr + n);
	sort(sortArr.begin(), sortArr.end(), cmp);
	for(int i=0;i<n;i++){
		cout<<sortArr[i]<<" ";
	}
}

int main()
{
	string arr[1000];
	int n;
	cout<<"enter size: ";
	cin>>n;
	cout<<"enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sortBigIntegers(arr,n);
}
