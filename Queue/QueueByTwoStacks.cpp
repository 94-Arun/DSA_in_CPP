#include<iostream>
#include<stack>
using namespace std;


// Method : Eager Transfer
//push() -> O(n)
//pop() -> O(1)
// class Queue{
//     stack<int> s1;
//     stack<int> s2;
// public:
//     // push operation O(n) time complexity
//     void push(int a){
//         // s1 -> s2
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(a);

//         // s1 -> s1
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }   

//     void pop(){
//         if(isempty()){
//             cout << "Queue is empty\n";
//             return;
//         }
//         s1.pop();
//     }

//     int front(){
//         if(isempty()){
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         return s1.top();
//     }

//     bool isempty(){
//         return s1.empty();
//     }

// };

// Method: Lazy Transfer
// pop() -> Amortized(1);
// push()-> O(1);
class Queue{
    stack<int> s1;
    stack<int> s2;
public:
     
void push(int a){
    s1.push(a);
}

void pop(){
    if(isempty()){
        cout << "Queue is empty\n";
        return;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}
int front(){
    if(isempty()){
        cout << "Queue is empty\n";
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}
bool isempty(){
    return s1.empty() && s2.empty();
}

};




int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    // q.pop();

    while(!q.isempty()){
        cout<<q.front()<<endl;
        q.pop();
    }

}