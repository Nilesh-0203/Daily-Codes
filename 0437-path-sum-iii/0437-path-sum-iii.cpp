/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total=0;
    void findPathSum(TreeNode* root, int targetSum,long long currSum,map<long long,int>&mp){
        if(root==NULL){
            return ;
        }
        currSum+=root->val;
        if(mp.find(currSum-targetSum)!=mp.end()){
            total+=mp[currSum-targetSum];
        }
        mp[currSum]++;
        findPathSum(root->left,targetSum,currSum,mp);
        findPathSum(root->right,targetSum,currSum,mp);
        mp[currSum]--;
        currSum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        map<long long,int>mp;
        mp[0]=1;
        findPathSum(root,targetSum,0,mp);
        return total;
    }
};