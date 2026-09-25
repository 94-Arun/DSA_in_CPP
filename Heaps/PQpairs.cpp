#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct comparePair{
    bool operator () (pair<string,int> &p1,pair<string,int> &p2){
        return p2.second < p1.second;
    }
};

int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePair> pq;

    pq.push(make_pair("arun",500));
    pq.push(make_pair("jack",400));
    pq.push(make_pair("meloni",1000));
    pq.push(make_pair("brad",300));

    cout<<pq.top().second<<endl;
}