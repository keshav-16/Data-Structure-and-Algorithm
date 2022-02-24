#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if(a == 0){
        return b;               //  gcd(0,b) = gcd(b,0) = b and gcd(a,0) = a
    }
    else{
        return gcd(b%a , a);
    }
}

int main(){
    
    int a,b;
    cin>>a>>b;

    int x = gcd(a,b);

    cout<<x<<endl;

    return 0;
}