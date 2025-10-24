# include<iostream>
using namespace std;

// Brute Force Approach to find Maximum Subarray Sum
void MaxSubArraySum(int arr[],int n){
    int maxSum = INT_MIN;
    for(int start = 0;start < n; start++){
        for(int end = start; end < n; end++){
            int sum = 0;
            for(int i = start;i<=end;i++){
                sum += arr[i];
            }
            // cout<<sum<<",";
            maxSum = max(maxSum,sum); 
        }
    }
    cout<<"Max Subarray Sum is:"<<maxSum<<endl;
}

// Optimized Approach to find Maximum Subarray Sum
void MaxSubArraySum2(int arr[],int n){
    int maxSum = INT_MIN;
    for(int start = 0;start < n; start++){
        int sum = 0;
        for(int end = start; end < n; end++){
            sum += arr[end];
            maxSum = max(maxSum,sum);
        }
    }
    cout<<"Max Subarray Sum is:"<<maxSum<<endl;

}

// Kdane's Algorithm

void MaxSubArraySum_Kdanes_algo(int arr[],int n){
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0;i<n;i++){
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum < 0)
            currSum = 0;
    }
    cout<<"Max Subarray Sum is:"<<maxSum<<endl;

}


int main(){
    int arr[6];
    cout<<"Enter the Elemenst of the Arrar : ";
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    // MaxSubArraySum(arr,6);
    // MaxSubArraySum2(arr,6);
    MaxSubArraySum_Kdanes_algo(arr,6);


    return 0;
}