#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    char data;
    struct node* next;
}node;

node* inLast(node* head,char data){
    node* x;
    x = (struct node*)malloc(sizeof(struct node));
    node* p = head;
    while(p->next != head){
        p = p->next;
    }
    x->next = p->next;
    x->data = data;
    p->next = x;
    return x;
}

void delFirst(node* head){
    node* ptr1 = head;
    node* ptr2 = head->next;
    if(ptr2 == head){
        cout<<"Empty"<<endl;
    }
    else{
    ptr1->next = ptr2->next;
    cout<<ptr2->data<<endl;
    free(ptr2);
    
    }
}

void display(node* head){
    node* p = head->next;
    while(p != head){
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main(){
    node* head;
    head = (node*)malloc(sizeof(node));
    head->next = head;

    int k=0;
    char data;
    

    while(k != 4){
        cin>>k;

        if(k == 1){
            cin>>data;
            inLast(head,data);
        }
        else if(k == 2){
            delFirst(head);
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