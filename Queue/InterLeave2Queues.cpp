#include<iostream>
#include<queue>
using namespace std;


void interleave(queue<int>& orglQueue){
    int n = orglQueue.size();
    queue<int> tempQueue;


    if(orglQueue.empty()){
         cout<<"-1"<<endl;
         return;
    }
    for(int i = 0;i<n/2;i++){
        tempQueue.push(orglQueue.front());
        orglQueue.pop();
    }

    while(!tempQueue.empty()){
        orglQueue.push(tempQueue.front());
        tempQueue.pop();

        orglQueue.push(orglQueue.front());
        orglQueue.pop();
    }

    // used when queue is pass by value as parameter in to the function 

    // while(!orglQueue.empty()){
    //     cout<<orglQueue.front()<<" , ";
    //     orglQueue.pop();
    // }
    // cout<<endl;

}

// main 
int main(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);



    interleave(q);

    // print in main — q now has interleaved result
    int size = q.size();
    int count = 0;
    while(!q.empty()){
        cout << q.front();
        q.pop();
        count++;
        if(count != size) cout << " , ";
    }
    cout << endl;

    return 0;
}