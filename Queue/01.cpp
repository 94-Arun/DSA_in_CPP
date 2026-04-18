#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }

};
// queue class
class Queue{
    Node *front;
    Node *rear;

public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val){
        Node *newnode = new Node(val);
        if(front == NULL){
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    // It is a Dequeue code
    int dequeue(){
        if(front == NULL){
            cout<<"QUEUE IS Empty";
            return -1;
        }  
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        int data = temp->data;
        delete temp;
        if(front == NULL){
            rear = NULL;
        }
        return data;
    }
    void display(){
        Node *temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;    
        }
        cout<<endl<<"NULL"<<endl;
    }
};
// main

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout<<"Deleted Element:"<<q.dequeue()<<endl;
    q.display();

    return 0;
}