#include<iostream>
#include<deque>
using namespace std;

// class
class Stack{
    deque<int> deq;
public:

    void push(int data){
        deq.push_front(data);
    }
    void pop(){
        deq.pop_front();
    }
    int top(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }

};

// main
int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.top()<<endl;
    cout<<endl;

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}