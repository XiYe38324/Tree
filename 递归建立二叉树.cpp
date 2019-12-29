#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct node{
    char value;
    struct node * Left;
    struct node * Right;
}Node;
char s[10005];
int k = 0;
void Buildbt(Node **bt)
{ 
	char n;
	cin>>n;
	if(n == '#'){ 
		*bt = NULL;
	} 
	else{
		*bt=(Node *)malloc(sizeof(Node));
      	(*bt)->value = n;
      	Buildbt(&((*bt)->Left));
      	Buildbt(&((*bt)->Right));
    }
}

void inorder(Node *tree)
{
	if(tree){
		inorder(tree->Left);
		cout<<tree->value;
		s[k++] = tree->value;
		inorder(tree->Right);
	}
}
int main()
{
    Node *bt = NULL;
    Buildbt(&bt);
    inorder(bt);
	cout<<endl;
   	for(int i = k-1;i >= 0;i--){
   		cout<<s[i];
	}
	cout<<endl;
    return 0;
}

