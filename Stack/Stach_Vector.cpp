#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
    }    
    void pop(){
        vec.pop_back();
    }
    void top(){
        int idx = vec.size()-1;
        cout<<" "<<vec[idx];
    }
    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);

    // s.top();
    while(!s.isEmpty()){
        s.top();
        s.pop();
    }

    return 0;
}

