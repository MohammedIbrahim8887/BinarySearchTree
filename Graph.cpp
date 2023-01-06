#include<iostream>
using namespace std;
struct node{
	int data;
	node*right;
	node*left;
}*temp,*cur,*bef,*curLeft,*curRight,*aft;
struct BST{
	node*root;
	int size;
}T;
void initialize(BST&);
void insert(BST&);
void preOrder(node*);
void postOrder(node*);
void inOrder(node*);
void deleteUsingCopy(node* t);
void deleteUsingMerge(node* t);
node* search(node* t,int value);
int main(){
	int n;
	BST t;
	initialize(t);
	cout<<"how many nodes do you want to insert?";
	cin>>n;
	for(int i=1;i<=n;i++){
		insert(t);
	}
	cout<<"you created a tree of "<<t.size<<"nodes"<<endl;
	cout<<"the node of the tree in pre order is:\n";
	preOrder(t.root);
	cout<<endl;
	cout<<"the node of the tree in post order is:\n";
	postOrder(t.root);
	cout<<endl;
	cout<<"the node of the tree in inorder is:\n";
	inOrder(t.root);
	cout<<"Enter value to be searched:"<<endl;
	cin>>n;
	node* val = search(t.root,n);
	deleteUsingMerge(val);	
	cout<<"the node of the tree in pre order is:\n";
	preOrder(t.root);
}


void initialize(BST& T){
	T.root = NULL;
	T.size = 0;
}

void insert(BST& T){
	int i = 0;
	cur= T.root;
	temp= new node;
	temp->right =NULL;
	temp->left = NULL;
	cout<<"enter the value of the node: ";
	line:
	cin>>temp->data;
	if(T.root ==NULL){
		T.root = temp;
	}else{
		while(!i){
			if((temp->data) > (cur->data)){
				if(cur->right == NULL){
					cur->right=temp;
					i=1;				
				}else{
					cur=cur->right;
				}
			}else if((temp->data)<(cur->data)){
				if(cur->left == NULL){
					cur->left = temp;
					i=1;
				}else{
					cur = cur->left;
				}
			}else{
				cout<<"duplicated key enter the value again"<<endl;
				goto line;
			}
		}
	}
	T.size++;
}

void preOrder(node *R){
	if(R!=NULL){
		cout<<R->data;
		cout<<" ";
		preOrder(R->left);
		preOrder(R->right);
	}
}
void inOrder(node *R){
	if(R!=NULL){
		preOrder(R->left);
		cout<<R->data;
		preOrder(R->right);
	}
}
void postOrder(node *R){
	if(R!=NULL){
		postOrder(R->left);
		postOrder(R->right);
		cout<<R->data<<" ";
	}
}

node* search(node* t,int value){
	if(t == NULL)
		return NULL;
	if(value == t->data)
		return t;	
	else if(value < t->data){
		bef = t;
		search(t->left,value);
	}
	else{
		bef = t;
		search(t->right,value);
	}
}

void deleteUsingCopy(node* t){
	curLeft = t->left;
	curRight = t->right;
	bef->right = curRight;
	aft = curRight->left;
	cout<<curLeft->data;
	while(aft->left != NULL){
		aft = aft->left;
	}	
	aft->left = curLeft;
	t->left = NULL;
	t->right = NULL;
	cout<<t<<"has been deleted";
	delete t;
}

void deleteUsingMerge(node* t){
	curLeft = t->left;
	curRight = t->right;
	if(t->left!=NULL){
		if(curLeft->right!=NULL){
			aft = curLeft->right;
			while(aft->right!=NULL){
				bef = aft;
				aft = aft->right;
			}
			cout<<t->data<<" has been deleted"<<endl;
			int value = aft->data;
			t->data = value;
			bef->right = NULL;
			delete aft;
		}
		else{
			aft = curRight->left;
			while(aft->left!=NULL){
				bef = aft;
				aft = aft->left;
			}
			cout<<t->data<<" has been deleted"<<endl;
			int value = aft->data;
			t->data = value;
			bef->left = NULL;
			delete aft;
		}
	}
	else{
			aft = curRight->left;
			while(aft->left!=NULL){
				bef = aft;
				aft = aft->left;
			}
			cout<<t->data<<" has been deleted"<<endl;
			int value = aft->data;
			t->data = value;
			bef->left = NULL;
			delete aft;
	}
}
