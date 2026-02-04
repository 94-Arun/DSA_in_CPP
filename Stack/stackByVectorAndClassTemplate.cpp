#include<iostream>
#include<vector>
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
            cout<<"Stack Overflow\n";
            return;
        }
        vec.pop_back();
    }
    T top(){
        if(isEmpty()){
            throw runtime_error("Stack is empty");
        }
        return vec.back();
    }
    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack<char> s;
    s.push('c');
    s.push('b');
    s.push('a');

    // s.top();
    // s.pop();
    while(!s.isEmpty()){
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}

