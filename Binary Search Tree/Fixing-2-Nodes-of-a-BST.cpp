/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	
	root=correctBST(root);

	inorder(temp,root);

	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0\n";
	}
	}
    return 0;
}// } Driver Code Ends

/*Complete the function
Node is as follows:
struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
*/

void findFault(Node *root, Node *& start, Node *& middle, Node *& last, Node *& prev) {
    if(root==NULL) return;
    findFault(root->left,start,middle,last,prev);
    if(prev==NULL) {
        prev=root;
    } else {
        if(prev->data > root->data) {
            if(start==NULL) {
                start = prev;
                middle = root;
            } else {
                middle = prev;
                last = root;
            }
        }
        prev=root;
    }
    findFault(root->right,start,middle,last,prev);
}

struct Node *correctBST( struct Node* root )
{
    // add code here.
    Node *start=NULL, *middle=NULL, *last=NULL, *prev=NULL;
    findFault(root, start, middle, last, prev);
    int temp;
    if(last!=NULL) middle=last;
    temp = start->data;
    start->data = middle->data;
    middle->data = temp;
    return root;
}

