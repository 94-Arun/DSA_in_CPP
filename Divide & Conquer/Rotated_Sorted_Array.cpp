#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &arr,int target){
    int si = 0,ei = (int)arr.size()-1;
    while(si <= ei){
        int mid = si + (ei - si)/2;

        if(arr[mid]==target) return mid;


        if(arr[si]<=arr[mid]){
            if(arr[si] <= target && target <= arr[mid]) 
                ei = mid - 1;
            else  
                si = mid+1;
        }
        else{
            if(arr[mid]<= target && target <= arr[ei])  
                si = mid + 1;
            else 
                 ei = mid-1;
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {4,5,6,7,0,1,2};
    int s = search(arr,1);
    cout<<"Desired Index : "<< s <<endl;
    return 0;
}