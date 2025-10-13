/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int non_adj(Node *root,int check,unordered_map<Node*,vector<int>>&dp)
    {
        
        if(!root)return 0;
        if(dp[root].empty())dp[root] = vector<int>(2,-1);
        if(dp[root][check]!=-1)return dp[root][check];
        int take= INT_MIN;
        int nottake = INT_MIN;
        if(check)
        {
            take = root->data + non_adj(root->left,0,dp) + non_adj(root->right,0,dp);
            nottake = non_adj(root->right,1,dp)+non_adj(root->left,1,dp);
        }
        else
        {
            nottake = non_adj(root->right,1,dp) + non_adj(root->left,1,dp);
        }
        return dp[root][check] = max(take,nottake);
    }
    int getMaxSum(Node *root) {
        unordered_map<Node*,vector<int>>dp;
        return non_adj(root,1,dp);
    }
};