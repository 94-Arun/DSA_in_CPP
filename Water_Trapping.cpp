#include<iostream>
#include <climits>
using namespace std;


void WaterTrapped(int heightes[],int n){
    int rightMax[20000];int leftMax[20000];
    leftMax[0] = heightes[0];
    rightMax[n-1] =heightes[n-1];

    for(int i = 1;i<n;i++){
        leftMax[i] = max(leftMax[i-1],heightes[i-1]);
    }
    for(int i = n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1],heightes[i+1]);
    }

    int watertrap = 0;
    for(int i = 0;i<n;i++){
        int currwatertrap = min(leftMax[i],rightMax[i]) - heightes[i];
        if(currwatertrap > 0){
            watertrap += currwatertrap; 
        }
    }
    cout<<"Water Trapped : "<<watertrap<<endl;
}
int main(){
    int heightes[7] = {4,2,0,6,3,2,5};
    int n = sizeof(heightes)/sizeof(int);

    WaterTrapped(heightes,n);
    return 0;
}