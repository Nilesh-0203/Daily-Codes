//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    void createMap(int in[],map<int,int>&mp,int n){
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
    }
    Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,map<int,int>&mp){
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=post[index--];
        Node* root=new Node(element);
        int position=mp[element];
        root->right=solve(in,post,index,position+1,inorderEnd,n,mp);
        root->left=solve(in,post,index,inorderStart,position-1,n,mp);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postOrderIndex=n-1;
        map<int,int>mp;
        createMap(in,mp,n);
        Node* ans=solve(in,post,postOrderIndex,0,n-1,n,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends