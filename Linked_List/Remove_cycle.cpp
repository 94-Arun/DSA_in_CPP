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

// Detect a loop or cycle in a linked list
bool iscycle(){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"Cycle Exist"<<endl;
            return true;
        }
    }

    cout<<"Cycle not exist "<<endl;
    return false;
}


void removeCycle(){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    bool cycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycle = true;
            break;
        }
    }

    if(cycle){
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }
        while(slow != fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

};



int main(){ 

    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.tail->next = ll.head;
    ll.iscycle();
    ll.removeCycle();
    ll.iscycle();



}
 