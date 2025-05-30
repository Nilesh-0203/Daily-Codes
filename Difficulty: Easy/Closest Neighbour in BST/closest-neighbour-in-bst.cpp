/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void preorder(Node* root,int k,int& ans){
        if(root==NULL){
            return;
        }
        if(root->data<=k && root->data>ans)ans=root->data;
        if(root->data > k)preorder(root->left,k,ans);
        else preorder(root->right,k,ans);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int ans=-1;
        preorder(root,k,ans);
        return ans;
    }
};