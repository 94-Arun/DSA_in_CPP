
#include <iostream>
using namespace std;
#include<vector>

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> temp;
        int si1 = 0,si2 = 0;
        int ei1 = m-1,ei2 = n-1;

        while(si1<=ei1 && si2<=ei2){
            if(nums1[si1] <= nums2[si2]){
                temp.push_back(nums1[si1++]);
            }
            else{
                temp.push_back(nums2[si2++]);
            }
        }
        while(si1<=ei1){
                temp.push_back(nums1[si1++]);
            }

        while(si2<=ei2){
                temp.push_back(nums2[si2++]);
            }
        
        for(int x : temp) cout << x <<" ";
}        
        
        

int main() {
    vector<int> nums1 = {1,2,6};
    vector<int> nums2 = {1,2,3,4,8};
    merge(nums1,3, nums2,5);
    
    return 0;
}