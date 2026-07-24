/* Structure of Binary Tree Node
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
    int maxi;
  
  
    pair<int, int>solve(Node* node){
        
        if(!node){
            return {0, 0};
        }
        
        if(!node->left && !node->right){
            return {node->data, 1};
        }
        
        auto [lv, lc]=solve(node->left);
        auto [rv, rc]=solve(node->right);
        
        if(node->data+1==lv){
            if(node->data+1==rv){
                maxi=max(maxi, max(lc, rc)+1);
                return {node->data, max(lc, rc)+1};
            }else{
                maxi=max(maxi, lc+1);
                return {node->data, lc+1};
            }
        }else if(node->data+1==rv){
            maxi=max(maxi, rc+1);
            return {node->data, rc+1};
        }else return {node->data, 1};
    }
  
    int longestConsecutive(Node* root) {
        // code here
        maxi=-1;
        solve(root).second;
        return maxi==1?-1:maxi;
    }
};