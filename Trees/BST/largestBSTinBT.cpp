#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *left,*right;

    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    // Node(int x) : val(x),left(nullptr),right(nullptr){}
};

struct NodeValue{
public:
    int maxnode,minnode,maxsize;

    NodeValue(int maxnode,int minnode,int maxsize ){
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }
};

NodeValue BSTinBT(Node* root){
    if(root == NULL) return NodeValue(INT_MIN,INT_MAX,0);



    NodeValue left = BSTinBT(root->left);
    NodeValue right = BSTinBT(root->right);

    // if its Binary Tree
    if(left.maxnode < root->val  && right.minnode > root->val){
        return NodeValue(max(right.maxnode,root->val),min(left.minnode,root->val),left.maxsize + right.maxsize + 1);

    }
    // if not a binary tree 
    return NodeValue(INT_MAX,INT_MIN,max(left.maxsize,right.maxsize));

}

int main(){
    Node* root = new Node(50); // root
    // left SubTree
    root->left = new Node(30);
    root->left->left = new Node(10);
    root->left->right = new Node(60);
    // right SubTree
    root->right = new Node(70);
    root->right->left = new Node(40);
    root->right->right = new Node(65);
    root->right->right->left = new Node(75);
    root->right->right->right = new Node(85);

    NodeValue ans = BSTinBT(root);
    cout<<ans.maxsize<<endl;



    // Node* root = new Node(50);
    // root->left = new Node(30);
    // root->left->left = new Node(5);
    // root->left->right = new Node(20);

    // root->right = new Node(60);
    // root->right->left = new Node(45);
    // root->right->right = new Node(70);
    // root->right->right->left = new Node(65);
    // root->right->right->right = new Node(80);

}




