# include<iostream>
using namespace std;

// Print all subarrays of an array

void printSubarrays(int arr[],int n){
    for(int start = 0;start < n; start++){
        for(int end = start; end < n; end++){
            for(int i = start;i<=end;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;    
    }
}

int main(){
    int arr[5];
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    printSubarrays(arr,5);
    return 0;
}