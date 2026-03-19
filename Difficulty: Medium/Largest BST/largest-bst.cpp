/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
     vector<int> find(Node*root,int &ans){
        if(!root)return {0,0,0};
        // first index = number of elements till.
        // second inxex = min value till.
        // third index = max value till.
        
        vector<int>l = find(root->left,ans);
        vector<int>r = find(root->right,ans);
        
        if(l[0]==-1 || r[0]==-1)return {-1,0,0}; // for invalid tree.
        
        if(l[0]==0 && r[0]!=0){ // only right child exist.
            
            if(root->data < r[1]){
                int mini = min(root->data,r[1]);
                int maxi = max(root->data,r[2]);
                int num = 1+r[0];
                ans= max(ans,num);
                return {num,mini,maxi};
            }
            else return {-1,0,0};
        }
        else if(l[0]!=0 && r[0]==0){ // only left child exist.
            
            if(root->data > l[2]){
                int mini = min(root->data,l[1]);
                int maxi = max(root->data,l[2]);
                int num = 1+l[0];
                ans= max(ans,num);
                return {num,mini,maxi};
            }
            else return {-1,0,0};
        }
        else if(l[0]==0 && r[0]==0){ // leaf node
            
            return {1,root->data,root->data};
            
        }
        else{ // middle node
                
                if(root->data <= l[2] || root->data >= r[1])return {-1,0,0};
                
                int mini = min(root->data,min(l[1],r[1]));
                int maxi = max(root->data,max(l[2],r[2]));
                int num  = 1+l[0]+r[0];
                ans = max(ans,num);
                return {num,mini,maxi};
            
        }
        
        return {-1,0,0};
    }
    
    int largestBst(Node *root) {
        // Your code here
        int ans = 1;
        find(root,ans);
        return ans;
    }
};