#include<iostream>
#include<vector>
using namespace std;

vector<int> PairSum(vector<int> arr, int target){
    int start = 0,end = arr.size()-1;

    while(start<end){
        int currSum = arr[start] + arr[end];
        if(currSum == target){
            return {start ,end};
        }
        else if(currSum > target){
            end--;
        }    
        else{
            start++;  
        }      
    }
    return {};
}

int main(){
    vector<int> vec1= {2,7,11,15};
    int target = 9;
    vector<int> ans = PairSum(vec1,target);
    cout<<ans[0]<<","<<ans[1]<<endl;

    return 0;
}
