/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* Successor(Node* root, int key,Node* ans) {
         if(root==NULL)return ans;
         if(root->data>key){
            ans=root;
            Successor(root->left,key,ans);
         }
         else Successor(root->right,key,ans);
    }
    Node* Predecessor (Node* root, int key,Node* ans) {
         if(root==NULL)return ans;
         if(root->data<key){
            ans=root;
            Predecessor(root->right,key,ans);
         }
         else Predecessor(root->left,key,ans);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* s=Successor( root, key,NULL);
        Node* p=Predecessor( root, key,NULL);
        ans.push_back(p);
        ans.push_back(s);
        return ans;
    }
};