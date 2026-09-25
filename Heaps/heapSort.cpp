#include<iostream>
#include<vector>
using namespace std;


void heapify(int i ,vector<int>& v,int n){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && v[left] > v[maxI]){
        maxI = left;
    }
    if(right < n && v[right] > v[maxI]){
        maxI = right;
    }

    if(maxI != i){
        swap(v[maxI],v[i]);
        heapify(maxI,v,n);
    }
}

void heapSort(vector<int>& v){
    int n = v.size();

    for(int i = n/2-1;i>=0;i--){
        heapify(i,v,n);
    }

    for(int i = n-1;i >= 0;i--){
        swap(v[0],v[i]);
        heapify(0,v,i);
    }
}


int main(){
    vector<int> v = { 1,4,2,5,3};
    heapSort(v);
    for(int i = 0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}