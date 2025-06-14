/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* root1,Node* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
            return false;
        }
        
        if(root1->data!=root2->data){
            return false;
        }
        
        bool leftNode=solve(root1->left,root2->right);
        bool rightNode=solve(root1->right,root2->left);
        
        return leftNode && rightNode;
    }
    bool isSymmetric(Node* root) {
        // Code here
        return solve(root->left,root->right);
    }
};