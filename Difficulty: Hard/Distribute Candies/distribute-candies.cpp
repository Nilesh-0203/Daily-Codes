/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int solve(Node* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int r=solve(root->right,ans);
        int l=solve(root->left,ans);
        ans+=abs(r)+abs(l);
        return root->data+l+r-1;
    }
    int distCandy(Node* root) {
        // code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};