#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int minCost(vector<int> length){
    priority_queue<int,vector<int> , greater <int>> pq(length.begin(),length.end()); // O(n )
    int cost = 0;

    while(pq.size() > 1){
        int c1 = pq.top();
        pq.pop();
        int c2 = pq.top();
        pq.pop();

        int d = c1 + c2;
        pq.push(d);
        cost += d; 
    }

    return cost;
}

int main(){

    vector<int> length = {4,3,2,6};
    cout<<"Min Cost : " << minCost(length)<<endl;

    return 0;    
}