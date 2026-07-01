#include<iostream>
#include<vector>
using namespace std;

void fractionalKapscack(vector<int> &val,vector<int> &wt,int weight){
    vector<pair<double,int>> ratio(val.size(),make_pair(0.0,0));

    for(int i = 0;i<val.size();i++){
        // ratio[i].first = val[i]/(double)wt[i];
        // ratio[i].second = i;
        int r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),[](pair<double,int> p1,pair<double,int> p2){
        return p1.first>p2.first;
    });

    int ans = 0;

    for(int i = 0;i<val.size();i++){
        int idx = ratio[i].second;
        
        if(wt[idx]<=weight){
            ans += val[idx];
            weight -= wt[idx];
        }else{
            ans += (ratio[i].first*weight);
            weight = 0;
            break;
        }

    }
    cout<<"Maximum Total Value : "<<ans<<endl;

}



int main(){
    vector<int> val = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;

    fractionalKapscack(val,weight,w);

}