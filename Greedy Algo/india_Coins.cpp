#include<iostream>
#include<vector>
using namespace std;

int indianCoins(int n){

    int coins[] = {1,2,3,5,10,20,50,100,200,500,2000};

    int ans = 0;
    for(int i = 11;i>=0 && n>0;i--){
        if(coins[i] <= n){
            ans += n/coins[i];
            n = n%coins[i];
        }
    }
    return ans;
}


int main(){
    int n = 121;
    cout<<"No. of Indian Coins Required : "<<indianCoins(n)<<endl;

}