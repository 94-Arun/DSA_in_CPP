#include<iostream>
using namespace std;
#include<vector>

void Merge_Sort(vector <int> &arr, int left, int right){
    if (left >= right)
        return;
    
    int mid =  left + (right - left) / 2;  

    Merge_Sort(arr,left,mid); 
    Merge_Sort(arr,mid+1,right);
    MergeArray(arr, left, mid, right);     

}

void MergeArray(vector <int> &arr, int left, int mid, int right){

}

int main(){

    vector<int> arr = {5, 2, 4, 6, 1, 3};

    Merge_Sort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    return 0;

    return 0;
}