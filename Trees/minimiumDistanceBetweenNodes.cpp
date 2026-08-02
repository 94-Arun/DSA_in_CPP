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

int Dis(Node* root,int n){

    if(root==NULL) return -1;
    if(root->val == n) return 0;

    int ldis = Dis(root->left,n);
    if(ldis != -1) return ldis+1;

    int rdis = Dis(root->right,n);
    if(rdis != -1) return rdis+1;

    return -1;
}

Node* lca(Node* root,int a,int b){
    if(root == NULL) return NULL;

    if(root->val == a || root->val == b) return root;

    Node* llca = lca(root->left,a,b);
    Node* rlca = lca(root->right,a,b);

    if(llca != NULL && rlca != NULL) return root;

    return llca == NULL ? rlca : llca;
}


int minDis(Node* root ,int a, int b){
    Node* LCA = lca(root,a,b);
    
    int ld = Dis(LCA,a);
    int rd = Dis(LCA,b);

    return ld+rd;
}

// main
int main(){
vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(node);

cout<<"Minimum Distance : "<<minDis(root,4,6);
cout<<endl;

return 0;
}
