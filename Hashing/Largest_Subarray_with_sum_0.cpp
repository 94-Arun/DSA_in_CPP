#include<iostream>
#include<vector>
using namespace std;

int largetZeroSumSubArray(vector<int> v){
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;

    for(int i= 0;i<v.size();i++){
        sum += v[i];
        if(mp.count(sum)){
            int len = i-mp[sum];
            ans = max(ans,len);
        }else{
            mp[sum] = i;
        }
    }
    return ans;

}

int main(){
    vector<int> arr = {15,2,-2,-8,7,1,5,6};

    int len = largetZeroSumSubArray(arr);
    cout<<"length : "<<len<<endl;
}

