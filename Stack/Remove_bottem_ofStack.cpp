#include<iostream>
using namespace std;
#include<vector>


template<class T>
class Stack{
    vector<T> vec;
public:
    void push(T val){
        vec.push_back(val);
    }    
    void pop(){
        if(isEmpty()){
            cout<<"Stcak Underflow";
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
        return vec.empty();
    }

    void removeBottem(){

        if(vec.size() == 1){
            pop();        // remove bottom element
            return;
        }    
        if(isEmpty()){
            throw runtime_error("Stack is empty");
            return;
        }
        T topElement = top();
        pop();
        removeBottem();
        push(topElement);

    }

    void pushAtBottom(Stack<T> &s, T val){
        if(s.isEmpty()){
            s.push(val);
            return;
        }
        T topElement = s.top();
        s.pop();
        pushAtBottom(s,val);
        s.push(topElement);
        return ;
    }
};

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);


    // cout<<s.top()<<endl;
    // s.removeBottem();

    s.pushAtBottom(s,5);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
        cout<<endl;
    }

    return 0;
}