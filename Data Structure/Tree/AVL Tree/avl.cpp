#include <bits/stdc++.h>
using namespace std;

class node{

    public:

    int data;
    node *left;
    node *right;
    int height;

};

int max(int a,int b){
    if(a>b){
        return a;
    }
    else if(b>a){
        return b;
    }
    else{
        return 0;
    }
}

int getHeight(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->height;
    }
}

node* init(int key){
    node* root = (node*)malloc(sizeof(node));
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;

    return root;
}

int getBalance(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return getHeight(root->left) - getHeight(root->right) ;
    }
}

node* leftRotate(node* x){
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    y->height = 1 + max(getHeight(y->left),getHeight(y->right));

    return y;
                
}

node* rightRotate(node* y){
    node* x = y->left;
    node* T2 = x->right;

    y->left = T2;
    x->right = y;

    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    y->height = 1 + max(getHeight(y->left),getHeight(y->right));

    return x;
                
}

node* insert(node* root,int key){
     node* prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            return root;
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

        next->height = 1 + max(getHeight(next->left),getHeight(next->right));

        int balance = getBalance(next);
 
    // Left Left Case
    if (balance > 1 && key < next->left->data)
        return rightRotate(next);
 
    // Right Right Case
    if (balance < -1 && key > next->right->data)
        return leftRotate(next);
 
    // Left Right Case
    if (balance > 1 && key > next->left->data)
    {
        next->left = leftRotate(next->left);
        return rightRotate(next);
    }
 
    // Right Left Case
    if (balance < -1 && key < next->right->data)
    {
        next->right = rightRotate(next->right);
        return leftRotate(next);
    }
 
    /* return the (unchanged) node pointer */
    return next;
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
    
    while(k != 3){
        cin>>k;

        if(k == 1){
            int i;
            cin>>i;
            insert(root,i);
        }
        else if(k == 2){
            inorder(root);
        cout<<endl;
        }
        else{
            exit(0);
        }
    }
    
    return 0;
}