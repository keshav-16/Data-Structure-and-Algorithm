#include <bits/stdc++.h>
using namespace std;

void subSeq(string s,int i,string c){
    if(i == s.length()){
        cout<<c<<endl;
        return ;
    }

    subSeq(s,i+1,c+s[i]);
    subSeq(s,i+1,c);

}

int main(){

    string s;
    cin>>s;

    string c;
    subSeq(s,0,c);

    return 0;
}