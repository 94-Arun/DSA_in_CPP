#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;
public: 

    void push(int a){
        // add to heap
        vec.push_back(a);

        // fix the heap
        int childIdx = vec.size()-1; // child Index
        int parentIdx = (childIdx-1)/2; // parent Index
        
        // max heap Condition 
        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]){ // for min heap use this conditionvec[childIdx] < vec[parentIdx]
            swap(vec[childIdx],vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    int pop(){

    }

    int top(){
        return vec[0];
    }

    bool isempty(){
        return vec.size() == 0;
    }

};

int main(){
    Heap hp;
    hp.push(12);
    hp.push(16);
    hp.push(5);
    hp.push(50);

    cout<<"Top = "<< hp.top()<<endl;

    return 0;
}