//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,bool> vis;
    Node *tar  =nullptr;
    int minTime(Node* root, int target) 
    {
        dfs1(root,target);
        return dfs2(tar)-1;
    }
    void dfs1(Node *root,int target){
        if(root == nullptr){
            return;
        }
        if(root->data == target){
            tar = root;
        }
        if(root->left != nullptr){
            par[root->left] =root;
        }if(root->right != nullptr){
            par[root->right]= root;
        }
        dfs1(root->left,target);
        dfs1(root->right,target);
    }
    int dfs2(Node* from){
        if(from == nullptr){
            return 0;
        }
        int lft = 0, rgt = 0, parent = 0;
        vis[from] =true;
        if(vis.find(from->left) == vis.end()){
            lft = dfs2(from->left);
        }
        if(vis.find(from->right) == vis.end()){
            rgt = dfs2(from->right);
        }
        if(par.find(from) != par.end() && vis.find(par[from]) == vis.end()){
            parent = dfs2(par[from]);
        }
        return 1 + max(max(lft, rgt), parent);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends