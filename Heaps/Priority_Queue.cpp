#include<iostream>
#include<queue>
using namespace std;

int main(){
    // priority is gratest element on top
    priority_queue<int> pq;

    pq.push(1);
    pq.push(17);
    pq.push(8);
    pq.push(98);
    cout<<"Top : "<<pq.top()<<endl;

    // prioroty is smallest lement 
    priority_queue<string,vector<string> , greater<string>> ps;

    ps.push("Arun");
    ps.push("kumar");
    ps.push("sonu");
    ps.push("hellow");

    while(!ps.empty()){
        cout<<"Top : "<<ps.top()<<endl;
        ps.pop();
    }
    
    return 0;
}