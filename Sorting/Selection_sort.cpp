#include<iostream>
using namespace std;

void Selection_sort(int arr[], int n){

    for(int i = 0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_index])
                min_index = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    
}


int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" " ;
    }
    
    Selection_sort(arr,n);

    cout<<endl;

    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" " ;
    }
    return 0;
}