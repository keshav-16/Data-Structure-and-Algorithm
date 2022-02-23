#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* init(int data){
    node* root;
    root = (node*)malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void search(node* root, int key){

    if(root == NULL){
        cout<<"NO"<<endl;
        return ;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else if(key > root->data){
        return search(root->right,key);
    }
    else if(key == root->data){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}


int main(){
    node* root;
    root = init(1);
    root->left = init(2);
    root->right = init(3);
    root->left->left = init(4);
    root->left->right = init(5);

    int x;
    cout<<"Enter the elements to be searched"<<endl;
    cin>>x;

    search(root,x);

    inorder(root);
    cout<<endl;
    
     return 0;
}