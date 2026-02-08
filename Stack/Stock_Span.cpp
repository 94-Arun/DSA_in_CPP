#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

// stock span program
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

    T top(){
        if(isEmpty()){
            throw runtime_error("Stack is empty");
        }
        return vec.back();
    }

    bool isEmpty(){
        return vec.empty();
    }

    vector<int> stockSpan(vector<int> &prices){
        int n = prices.size();
        vector<int> span(n);
        Stack<int> s;

        span[0] = 1;
        s.push(0);

        for(int i = 1; i < n; i++){
            while(!s.isEmpty() && prices[s.top()] <= prices[i]){
                s.pop();
            }

            span[i] = s.isEmpty() ? (i + 1) : (i - s.top());
            s.push(i);
        }
        return span;
    }
};

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};
    Stack<int> s;

    vector<int> span = s.stockSpan(prices);
    for(int x : span){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
