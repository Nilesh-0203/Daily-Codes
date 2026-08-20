/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans = -1e9;
    
    int fun (Node* root) {
        if(!root) return 1e9;
        
        int l = fun(root->left);
        int r = fun(root->right);
        
        ans = max({root->data - l, root->data - r, ans});
        
        return min({l, r, root->data});
    }
    
    int maxDiff(Node* root) {
        fun(root);
        return ans;
    }
};