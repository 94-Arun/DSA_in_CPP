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

pair<int,int> diameter(Node* root){
    if(root == NULL) return make_pair(0,0);

    // pair(diameter,height)
    pair<int,int> leftinfo = diameter(root->left);
    pair<int,int> rightinfo = diameter(root->right); 

    int currdiam = leftinfo.second + rightinfo.second + 1;
    int finaldiameter = max(currdiam,max(leftinfo.first,rightinfo.first));
    int height = max(leftinfo.second,rightinfo.second) + 1;

    return make_pair(finaldiameter,height);
}

// main
int main(){
vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(node);

cout<<"Diameter : "<< diameter(root).first<<endl;

    return 0;
}
