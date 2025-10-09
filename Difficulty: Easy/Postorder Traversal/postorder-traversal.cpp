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
  public:
    void solve(Node* root,vector<int>&v){
    if(root==NULL){
      return ;
    }
   solve(root->left,v);
   solve(root->right,v);
   v.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
         vector<int>v;
         solve(root,v);
         return v;
}
};