/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void solve(Node* root,int& count){
        if(root==NULL){
            return;
        }
        solve(root->left,count);
        count++;
        solve(root->right,count);
    }
    int getSize(Node* root) {
        // code here
        int count=0;
        solve(root,count);
        return count;
    }
};