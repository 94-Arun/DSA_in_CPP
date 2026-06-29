#include<iostream>
#include<vector>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;//ascending order
}

// pairs in C++

int main(){
    vector<pair<int,int>> pairs(3,make_pair(0,0));
    pairs[0] = make_pair(0,9);
    pairs[1] = make_pair(2,4);
    pairs[2] = make_pair(5,7);

    for(int i = 0; i<pairs.size();i++){
        cout<<pairs[i].first<<","<<pairs[i].second<<endl;
    }

    sort(pairs.begin(),pairs.end(),compare);

    cout<<"-----------Sorted-----------"<<endl;

    for(int i = 0; i<pairs.size();i++){
        cout<<pairs[i].first<<","<<pairs[i].second<<endl;
    }
}

