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
bool rootToNodePath(Node* root, int n, vector<int> &path){
    if(root == NULL) return false;

    path.push_back(root->val);
    if(root->val==n) return true;

    bool isleft = rootToNodePath(root->left,n,path);
    bool isright = rootToNodePath(root->right,n,path);

    if(isleft || isright) return true;

    path.pop_back();
    return false;
}

int lca(Node* root, int n1,int n2){

    vector<int> path1;
    vector<int> path2;
    
    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);

    int lca = -1;
    for(int i = 0, j = 0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i] != path2[j]) return lca;
        lca = path1[i];
    }
    return lca;


}




// main
int main(){
vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(node);

int LCA = lca(root,4,5);
cout<<"Least Common Ansestor : "<<LCA<<endl;

    return 0;
}
