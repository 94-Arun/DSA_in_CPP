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
        swap(vec[0],vec[vec.size()-1]);

        int d = vec[vec.size()-1];
        vec.pop_back();

        heapify(0);

        return d;
    }

    int top(){
        return vec[0];
    }

    bool isempty(){
        return vec.size() == 0;
    }
    
private:
    void heapify(int p){

        int lc = 2*p + 1;
        int rc = 2*p + 2;

        int maxIdx = p;

        if(lc < vec.size()-1 && vec[lc] > vec[p]){
            maxIdx = lc;
        }

        if(rc < vec.size()-1 && vec[rc] > vec[p]){
            maxIdx = rc;
        }

        swap(vec[maxIdx],vec[p]);

        if(maxIdx != p){
            heapify(maxIdx);
        }
        
    }

};

int main(){
    Heap hp;
    hp.push(12);
    hp.push(16);
    hp.push(5);
    hp.push(50);

    cout<<"Top = "<< hp.top()<<endl;

    int v = hp.pop();
    cout<<"deleted val : " << v<<endl;
    cout<<"Top = "<< hp.top()<<endl;
    return 0;
}