//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct Node
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void makePar(Node* root,map<Node*,Node*> &mp,vector<Node*> &leaf)
{
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        Node* n=q.front();
        q.pop();
        if(n->left)
        {
            mp[n->left]=n;
            q.push(n->left);
        }
        if(n->right)
        {
            mp[n->right]=n;
            q.push(n->right);
        }
        if(n->left==NULL && n->right==NULL)
        leaf.push_back(n);
    }
}
 
int printKDistantfromLeaf(Node* root, int k)
{   
    map<Node*,Node*> mp;
    vector<Node*> leaf;
    makePar(root,mp,leaf);
    
    set<Node*> ans;
    for(auto it:leaf)
    {
        queue<Node*> q;
        q.push(it);
        int lvl=-1;
        while(q.empty()==false)
        {
            Node* n=q.front();
            q.pop();
            lvl++;
            if(lvl==k)
            {
                ans.insert(n);
                break;
            }
            if(mp[n])
                q.push(mp[n]);
        }
    }
    return ans.size();
//Add your code here. 
}
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends