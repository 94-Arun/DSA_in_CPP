#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;
public:
    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            throw runtime_error("Stack Underflow");
        }
        vec.pop_back();
    }
    bool isEmpty(){
        return vec.empty();
    }

    T top(){
        if(isEmpty()){
            throw runtime_error("Stack is Empty");
        }
        return vec.back();

    }

};

void NextGrater(vector<int>& arr, vector<int>& ans){
    Stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx = idx-1; idx>=0;idx--){
        int curr = arr[idx];
        while(!s.isEmpty() && curr >= s.top()){
            s.pop();
        }
        if(s.isEmpty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }

        s.push(curr);
    }
        for(int i = 0;i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }    

int main(){
    // Stack<int> s;
    // s.push(10);
    // s.push(9);
    // s.push(8);
    // s.push(7);
    // s.push(6);

    // while(!s.isEmpty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    vector<int> arr = {6,8,0,1,2,3};
    vector<int> ans = {0,0,0,0,0,0};
    NextGrater(arr,ans);


    return 0;
}