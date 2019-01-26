#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node *insertData(node *root, int data){
	if(root == NULL){
		root = new node;
		root->data=data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data){
		root->left = insertData(root->left,data);
	}
	else{
		root->right = insertData(root->right,data);
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
void preorder(node *root){
	if(root != NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
int main()
{
	int n;
	int data;
	node *root = NULL;
	cout<<" enter elements number: ";
	cin>>n;
	cout<<" enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>data;
		root = insertData(root,data);
	}
	cout<<" inorder form is : ";
	inorder(root);
	cout<<endl;
	cout<<" preorder form is : ";
	preorder(root);
	cout<<endl;
	cout<<" postorder form is : ";
	postorder(root);
	cout<<endl;
}
