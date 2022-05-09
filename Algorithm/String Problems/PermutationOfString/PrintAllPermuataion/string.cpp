#include <bits/stdc++.h>
using namespace std;

string swap(string s,int l,int r){
    int temp;
    
    temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    return s;
}

void permuataion(string s,int l,int r){
    if(l == r){
        cout<<s<<endl;
        return ;
    }
    else{
    for(int i=l;i<=r;i++){
        s = swap(s,l,i);
        permuataion(s,l+1,r);
        s = swap(s,l,i);
    }
    }
}

int main(){

    string s;
    cin>>s;

    int l = 0;
    int r;
    r = s.length();

    permuataion(s,l,r-1);

    return 0;
}