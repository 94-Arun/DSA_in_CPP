#include<iostream>
#include<stack>
using namespace std;


class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    // push operation O(n) time complexity
    void push(int a){
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(a);

        // s1 -> s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }   

    // O(1)
    void pop(){
        s1.pop();
    }

    // O(1)
    int front(){
         return s1.top();
    }

    bool isempty(){
        return s1.empty();
    }

};



int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isempty()){
        cout<<q.front()<<endl;
        q.pop();
    }

}