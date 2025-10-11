/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxSum;
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        
        int one=l+r+root->data;
        int two=max(l,r)+root->data;
        int three=root->data;
        maxSum=max({one,two,three,maxSum});
        return max(two,three);
    }
    int findMaxSum(Node *root) {
        // code here
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};