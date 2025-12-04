#include<iostream>
using namespace std;
#include<vector>

int Partion(vector<int> &arr, int si, int ei){
    int pivot = arr[ei];
    int i = si;
    int j = si;

    while(j<ei){
        if(arr[j] < pivot){        
            cout << ((i == j) ? "true" : "false") << endl;
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    
    swap(arr[i],arr[ei]);

    return i;
    
}

void Quick_Sort(vector<int> &arr, int si, int ei){

    if(si>=ei) return;

    int PI = Partion(arr,si,ei);

    Quick_Sort(arr, si, PI-1);
    Quick_Sort(arr, PI+1, ei);
}



int main(){
vector<int> arr = {5,4,3,2,1};

    Quick_Sort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x <<" ";
    cout<<endl;

    return 0;
}