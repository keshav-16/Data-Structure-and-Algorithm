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

void insert(node* root, int key){
    node* prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            return ;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

        node* next;
        next = init(key);

        if(key < prev->data){
            prev->left = next;
        }
        else{
            prev->right = next;
        }

}

node* minValNode(node* root){
    node* temp = root;
    if(temp != NULL && temp->left != NULL){
        temp = temp->left ;
    }
    else{
        return temp;
    }
}

node* delete(node* root, int key){
    if(root == NULL){
        return root;
    }
    else if(key < root->key){
        root->left = delete(root->left , key);
    }
    else if(key > root->key){
        root->right = delete(root->right , key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else{
            node* temp = minValNode(root->right);
            root->key = temp->key;
            root->right = delete(root->right,temp->key);
        }
    }
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    node* root;
    int x ;

    cout<<"Enter the root node : "<<endl;
    cin>>x;
    root = init(x);

    int k=0;
    
    while(k != 4){
        cin>>k;

        if(k == 1){
            int i;
            cin>>i;
            insert(root,i);
        }
        else if(k == 2){
            int d ;
            cin>>d ;
            delete(root,d);
        }
        else if(k == 3){
            inorder(root);
        cout<<endl;
        }
        else{
            exit(0);
        }
    }
    
     return 0;
}