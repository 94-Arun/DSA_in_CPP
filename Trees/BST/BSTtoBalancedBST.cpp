#include<iostream>
using namespace std;
#include<vector>

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root,vector<int>& v){
    if(root == NULL) return;

    inorder(root->left,v);
    // cout<<root->data<<" ";
    v.push_back(root->data);
    inorder(root->right,v);
}

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* balanceBST(vector<int> v,int l,int r){
    if(l>r) return NULL;

    int mid = l + (r-l)/2;

    Node* curr = new Node(v[mid]);

    curr->left = balanceBST(v,l,mid-1);
    curr->right = balanceBST(v,mid+1,r);

    return curr;
}

int main(){
    Node* root = new Node(6);

    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    // preorder sequence
    // preorder(root);

    vector<int> v;
    inorder(root,v);

    // // print inorder sequence
    // for (int x : v) {
    // cout << x << " ";
    // }


    root = balanceBST(v,0,v.size()-1);
    preorder(root);

} 


