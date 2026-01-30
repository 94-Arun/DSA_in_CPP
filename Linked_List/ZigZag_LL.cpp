#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;


    Node(int val){
        data = val;
        next = NULL;
    }

};

class List{
public:    
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }    
    
    // operations on linked list
    
    void push_front(int data){
        Node* newnode = new Node(data);

        if (head == NULL){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }

    }


    void display(){
        Node* temp = head;
        if(head == NULL) cout<<"Empty List:"<<endl;
        else{
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            } 
            cout<<"NULL";
            cout<<endl;
            
        }
    }



Node* splitmid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL;
    }

    return slow;
}    

};



int main(){ 

    List ll;

    ll.push_front(0);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.display();

    return 0;
}
 