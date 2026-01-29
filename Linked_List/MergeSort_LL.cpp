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

    void push_back(int val){
        Node* newnode = new Node(val);
        if (head == NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display(Node* head){
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

Node* merge(Node* left , Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }
        else{
            ans.push_back(j->data);
            j = j->next;
        }
    }
    
    while(i != NULL){ 
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }    

    return ans.head;
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

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* righthead = splitmid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(righthead);

    return merge(left,right);
}
};



int main(){ 

    List ll;

    ll.push_front(0);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(4);
    ll.push_front(9);
    ll.display(ll.head);
    ll.head = ll.mergeSort(ll.head);
    ll.display(ll.head);

    


}
 