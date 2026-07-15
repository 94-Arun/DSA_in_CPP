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

// main
int main(){
vector<int> node = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,-1};
Node* root = buildTree(node);
cout<<"Root Node : "<<root->val<<endl;
    return 0;
}
