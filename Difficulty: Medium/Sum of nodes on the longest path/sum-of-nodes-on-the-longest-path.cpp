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
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>leftNode=solve(root->left);
        pair<int,int>rightNode=solve(root->right);
        
        if(leftNode.first>rightNode.first){
            return {leftNode.first+1,leftNode.second+root->data};
        }
        else if(leftNode.first<rightNode.first){
            return {rightNode.first+1,rightNode.second+root->data};
        }
        else{
            return {leftNode.first+1,max(leftNode.second,rightNode.second)+root->data};
        }
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return solve(root).second;
    }
};