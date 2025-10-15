/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int solve(int &ans,Node*root,int l,int r)
    {
        if(root==NULL)
          return 0;
        solve(ans,root->left,l,r);
        if(root->data>=l && root->data<=r)
        {
            ans+=root->data;
        }
        solve(ans,root->right,l,r);
        return ans;
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        int ans=0;
        return solve(ans,root,l,r);
    }
};
