#include<iostream>
using namespace std;

// circular Queue using Array
class Queue{
    int *arr;

    int capacity;
    int currsize;

    int f,r;
public:
    Queue(int n){
        this->capacity = n;
        arr = new int[n];
        currsize = 0;
        f = 0;
        r = -1;
    }

    void push(int val){
        if(currsize == capacity) {
            cout<<"Queue is full\n";
            return;
        } 
        r = (r+1)%capacity;
        arr[r] = val;
        currsize++;

    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is empty:\n";
            return;
        }
        f = (f+1)%capacity;
        currsize--; 
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is empty:\n";
            return -1;
        }
        return arr[f];
    }

    bool isEmpty(){
        return currsize == 0;
    }

    void printQueue(){
        if(isEmpty()){
            cout<<"Queue is empty:\n";
            return;
        }
        int i = 0;
        while(i != r+1){
            cout<<arr[i]<<" ";
            i++;
        }
        cout<<endl;

    }


};

int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    // q.push(7);
 
    q.printQueue();

    q.pop();
    q.printQueue();



    return 0;
}
