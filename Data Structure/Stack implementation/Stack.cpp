#include <bits/stdc++.h>
using namespace std;

#define max 100

typedef struct {
    int top;
    char arr[max];
}stackq;

void isEmpty (stackq* s){
    if(s->top == -1){
        cout<<"Empty"<<endl;
        exit(0);
    }
}

void isFull (stackq *s){
    if(s->top == (max -1)){
        cout<<"Full"<<endl;
    }
}

void push (stackq *s , char item){
    isFull(s);
    s->arr[++(s->top)] = item ;
}

char pop(stackq* s){
    isEmpty(s);
    char temp;
    temp = s->arr[(s->top)--] ;
    return temp;
}

void display(stackq* s){
    isEmpty(s);
    for(int i=0;i<=s->top;i++){
        cout<<s->arr[i]<<endl;
    }
}

int main(){
    stackq s;
    s.top = -1 ;

    int x=0;

    while(x != 4){
        cin>>x;

    if(x==1){
        char item;
        cin>>item;
        push(&s,item);
    }
    else if(x==2){
        char temp;
        temp = pop(&s);
        cout<<temp<<endl;
    }
    else if(x==3){
        display(&s);
    }
    else{
        exit(0);
    }
    }
    return 0;
}