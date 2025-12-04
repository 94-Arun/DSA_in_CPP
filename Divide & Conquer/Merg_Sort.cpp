#include<iostream>
using namespace std;
#include<vector>

void Merge(vector <int> &arr, int si, int mid, int ei){
    vector <int> temp;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }

        while(i<=mid){
            temp.push_back(arr[i++]);
        }

        while(j<=ei){
            temp.push_back(arr[j++]);

        }

        for(int idx = si,x = 0; idx<=ei; idx++){
            arr[idx] = temp[x++];
        }
}    

    void Merge_Sort(vector <int> &arr, int si, int ei){
    if (si >= ei)
        return;
    
    int mid =  si + (ei - si) / 2;  

    Merge_Sort(arr,si,mid); 
    Merge_Sort(arr,mid+1,ei);
    Merge(arr, si, mid, ei);     

}

int main(){

    vector<int> arr = {10,9,8,7,6,5,4,3,2,1,0};

    Merge_Sort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x <<" ";
    cout<<endl;

    return 0;
}