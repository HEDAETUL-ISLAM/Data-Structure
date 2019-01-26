#include<iostream>
using namespace std;

struct bstNode{
	int data;
	bstNode *left;
	bstNode *right;
};

bstNode *creatNewNode(int data){
	bstNode *newNode = new bstNode();
	newNode->data = data;
	newNode->left = newNode->right =NULL;
	return newNode;
}

bstNode *insert(bstNode *root, int data){
	if(root == NULL){
		root = creatNewNode(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

bool search(bstNode *root, int data){
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}
int main()
{
	bstNode *root = NULL;
	int n,data,number;
	cout<<"enter the elements number: ";
	cin>>n;
	cout<<"enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>data;
		root=insert(root,data);
	}
	cout<<"enter search elements: ";
	cin>>number;
	if(search(root,number) == true){
		cout<<"found !!"<<endl;
	}
	else{
		cout<<"not found :("<<endl;
	}
}  
