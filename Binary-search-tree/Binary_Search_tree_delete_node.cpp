# Binary_Search_tree_delete_node
Delete node from binary tree


#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node *creatNewNode(int data){
	node *newNode = new node();
	newNode->data = data;
	newNode->left  = newNode->right = NULL;
	return newNode;
}

node *insert(node *root, int data){
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

node *findMinNode(node *root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

node *Delete(node *root, int data){
	if(root == NULL){
		return root;
	}
	else if(data < root->data){
		root->left = Delete(root->left,data);
	}
	else if(data > root->data){
		root->right = Delete(root->right,data);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){
			node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			node *temp = root;
			root = root->left;
			delete temp;
		}
		else{
			node *temp = findMinNode(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	int n,dm,data;
	node *root = NULL;
	cout<<"enter the elements number: ";
	cin>>n;
	cout<<"enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>data;
		root = insert(root,data);
	}
	cout<<"enter the delete elements: ";
	cin>>dm;
	root = Delete(root,dm);
	cout<<"inorder form is: ";
	inorder(root);
	
}
