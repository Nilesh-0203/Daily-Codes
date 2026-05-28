/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    map<int,int>mp;
    void preorder(Node* root,int level){
        if(root!=NULL){
            mp[level]+=root->data;
            preorder(root->left,level-1);
            preorder(root->right,level+1);
            return;
        }
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        preorder(root,0);
        vector<int>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};