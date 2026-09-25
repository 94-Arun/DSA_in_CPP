#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Cars{
public: 
    int idx;
    int dist;

    Cars(int idx,int dist){
        this->idx = idx;
        this->dist = dist;
    }

    // comparator for min heap
    bool operator < (const Cars &obj) const{
        return this->dist > obj.dist;
    }
};

void nearbyCar(vector<pair<int,int>> pos,int k){
    vector<Cars> cars;

    for(int i = 0;i<pos.size();i++){
        int d = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Cars(i,d));
    }

    priority_queue<Cars> pq(cars.begin(),cars.end());

    for(int i = 0;i<k;i++){
        cout<<pq.top().idx<< " " << pq.top().dist<< endl;
        pq.pop(); 
    }
}

int main(){
    vector<pair<int,int>> pq;
    pq.push_back(make_pair(7,7));
    pq.push_back(make_pair(5,7));
    pq.push_back(make_pair(2,4));

    nearbyCar(pq,2);


}

