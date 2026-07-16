#include<iostream>
#include<vector>
using namespace std;

// node structure
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

static int idx = -1;

Node* buildTree(vector<int> node){
    idx++;

    if(node[idx] == -1) return nullptr;

    Node* currnode = new Node(node[idx]);
    currnode->left = buildTree(node);
    currnode->right = buildTree(node);

    return currnode;
}

// preorder
void preorder(Node* root){
    if(root == nullptr) return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

//postorder
void postorder(Node* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
    
}

//inorder
void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    
    
}

// main
int main(){
vector<int> node = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,-1};
Node* root = buildTree(node);
// cout<<"Root Node : "<<root->val<<endl;

preorder(root);
cout<<endl;
postorder(root);
cout<<endl;
inorder(root);
cout<<endl;

    return 0;
}
