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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        unordered_map<int,int>mp;
        int maxx = 0;
        for (int val : v) {
            mp[val]++;
            maxx = max(maxx, mp[val]);
        }
       vector<int> result;
        for (const auto& pair : mp) {
            if (pair.second == maxx) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};