#include <bits/stdc++.h>
using namespace std;

void insertionsort(int n,int arr[]){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j] ;
            j--;
        }
        arr[j+1] = key;
        }
    
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        arr[i] = b;
    }

    insertionsort(n,arr);

    return 0;
}