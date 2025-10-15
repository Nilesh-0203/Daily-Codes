/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int>v;
        inorder(root,v);
        if(v.size()<k){
            return -1;
        }
        return v[k-1];
    }
};