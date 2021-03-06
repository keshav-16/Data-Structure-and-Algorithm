#include <bits/stdc++.h>
using namespace std;

#define max 5

typedef struct{
    char arr[max];
    int front;
    int rear;
}dequeue;

void initialize(dequeue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(dequeue* q){
    if(q->rear == -1){
        return -1;                   // returns true
    }
    return 0;                        // returns false
}

int isFull(dequeue *q){
    if((q->front == 0 && q->rear == max-1) ||
            (q->rear == (q->front-1)%(max-1))){
        return -1;
    }
    return 0;
}

void enqueueR(dequeue* q , char x){
    if(isFull(q)){
        cout<<"Full"<<endl;
        exit(100);
    }
    else if(isEmpty (q)){
        q->front = 0;
        q->rear = 0;
        q->arr[0] = x ;
    }
    else{
        q->rear = (q->rear + 1) % max;
        q->arr[q->rear] = x;
    }
}

char dequeueF(dequeue* q){
    int temp = q->arr[q->front];
    if(isEmpty(q)){
        cout<<"Empty"<<endl;
        exit(100);
    }
    else if(q->rear == q->front){
        initialize(q);
    }
    else{
        q->front = (q->front + 1) % max ;
        
    }
    return temp;
}

void display(dequeue* q){
    if(isEmpty(q)){
        cout<<"Empty"<<endl;
        exit(100);
    }
    else{
    for(int i=(q->front);i<=(q->rear);i++){
        cout<<q->arr[i]<<endl;
    }
    }
}

int main(){
    dequeue q;
    initialize(&q);

    int x=0;

    while(x != 4){
        cin>>x;
        if(x == 1){
            char item;
            cin>>item;
            enqueueR(&q,item);
            }

        else if(x == 2){
            char tmp = dequeueF(&q);
            cout<<tmp<<endl;
            }

        else if(x == 3){
            display(&q);
            }

        else{
            exit(0);
        }
        }
    
        return 0;
}