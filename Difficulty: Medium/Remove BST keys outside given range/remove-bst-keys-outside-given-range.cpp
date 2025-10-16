/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  Node* solve(Node*root,int l,int r){
        if(!root) return NULL;
        
        if(root->data >= l && root->data <= r){
            root->left = solve(root->left,l,r);
            root->right = solve(root->right,l,r);
            return root;
        }
        else if(root->data > r ){
            return solve(root->left,l,r);
        }else return solve(root->right,l,r);
    }
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        return solve(root,l,r);
    }
};