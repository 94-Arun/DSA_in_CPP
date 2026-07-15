#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    
    sort(nums.begin(),nums.end());

    int n = 6;

    vector<vector<int>> result;

    // for(int i = 0;i<n-2;i++){
    //     if(i>0 && nums[i] == nums[i-1]) continue;
    //     for(int j = i+1;j<n-1;j++){
    //         if(j>i+1 && nums[j] == nums[j-1]) continue;
    //         for(int k = j+1;k<n;k++){
    //             if(k>j+1 && nums[k] == nums[k-1]) continue;
    //             if(nums[i] + nums[j] + nums[k] == 0){
    //                 result.push_back({nums[i],nums[j],nums[k]});
    //             }
    //         }
    //     }
    // }

    for(int i = 0;i<n-2;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int left = i+1,right = n-1;
        int target = -nums[i];

        while(left<right){

            if(target == nums[left] + nums[right]){
                result.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;

                while(left<right && nums[left] == nums[left-1]) left++;
                while(left<right && nums[right] == nums[right+1]) right--;
        
            }else if(target > nums[left] + nums[right]){
                left++;
            }else{
                right--;
            }

        }
        
    }



   for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
   }

    return 0;
}