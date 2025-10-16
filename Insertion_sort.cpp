#include<iostream>
using namespace std;

// Insertion sort
void InsertionSort(int arr[],int n){

    for(int i = 0; i<n-1; i++){
        int key = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[i]){
                key = j;
                
            }
            int temp = arr[i];
                arr[i] = arr[key];
                arr[key] = temp;
        }
    }


}

int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);

    for(int a = 0; a<n; a++){
        cout<<arr[a]<<" ";
    }
    cout<<endl;

    InsertionSort(arr,n);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}