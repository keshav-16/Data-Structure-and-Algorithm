#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    char data;
    struct node* next;
}node;

node* inIndex(node* head,char data,int i){
    node* x;
    x = (struct node*)malloc(sizeof(struct node));
    node* p = head;
    int count = 1;
    while(p->next != NULL){
        if(count != i){
        p = p->next;
        count++;
        }
        else{
            break;
        }
        
    }
    x->next = p->next;
    x->data = data;
    p->next = x;
    return x;
}

void delIndex(node* head,int i){
    node* p = head;
    int count = 0;
    node* ptr;
     while(p->next != NULL){
        if(count != i-1){
        p = p->next;
        count++;
        }
        else{
            break;
        }
        
    }
    if(p->next == NULL){
        cout<<"Not Available"<<endl;
    }
    else{
    ptr = p->next;
    p->next = ptr->next;
    cout<<ptr->data<<endl;
    free(ptr);
    }
}

void display(node* head){
    node* p = head->next;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main(){
    node* head;
    head = (node*)malloc(sizeof(node));
    head->next = NULL;

    int k=0;
    char data;
    int i;

    while(k != 4){
        cin>>k;

        if(k == 1){
            cin>>i;
            cin>>data;
            inIndex(head,data,i);
        }
        else if(k == 2){
            cin>>i;
            delIndex(head,i);
        }
        else if(k == 3){
            display(head);
        }
        else{
            exit(0);
        }
    }
    return 0;
}