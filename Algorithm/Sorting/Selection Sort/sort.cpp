#include <bits/stdc++.h>
using namespace std;

void selectionsort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int min = arr[i];
        int x=i;
        for(int j=i+1;j<n;j++){
                if(min > arr[j]){
                    min = arr[j];
                    x=j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[x];
            arr[x] = temp;
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

    selectionsort(n,arr);

    return 0;
}