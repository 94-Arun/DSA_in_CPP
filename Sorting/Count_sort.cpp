#include<iostream>
using namespace std;

void Count_sort(int arr[],int n){
    int freq[100000] = {0};
    int minval = INT_MAX , maxval = INT_MIN;
    for(int i = 0; i<n; i++){
        minval = min(minval,arr[i]);
        maxval = max(maxval,arr[i]);
    }

    // Step 1  - O(n)
    for(int i = 0; i<n; i++){
        freq[arr[i]]++;
    }

    // Step 2 - O(range) = max - min
    for(int i=minval,j=0; i<=maxval; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
}

int main(){
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    Count_sort(arr,n);

    cout<<endl;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}