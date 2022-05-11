#include <bits/stdc++.h>
using namespace std;

void bubblesort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubblesort(n,arr);

    return 0;
}