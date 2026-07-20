#include<iostream>
#include<vector>
#include<queue>
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

int height(Node* root){
    if(root == NULL) return 0;

    int leftht = height(root->left);
    int rightht = height(root->right);

    int currht = max(leftht,rightht) + 1;

    return currht;
}


// main
int main(){
vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(node);

cout<<height(root)<<endl;

    return 0;
}
