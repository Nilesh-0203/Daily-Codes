//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void solve(Node* root, vector<int>&in ,  vector<int>&leaf )
    {
        if(root==0)
        return ;
        if(root->left==0 && root->right==0)
        leaf.push_back(root->data);
        solve(root->left, in, leaf);
        in.push_back(root->data);
        solve(root->right, in , leaf);
        
    }
    bool isDeadEnd(Node *root)
    { 
        vector<int>in;
        vector<int>leaf;
        solve(root,in, leaf);
        for(int i =0;i< leaf.size(); i++)
        {  int c=0, d=0;
            for(int j=0;j< in.size(); j++)
            {
                if(leaf[i]==1&& leaf[i]+1==in[j] )
                return true ;
                if(leaf[i]-1==in[j])
                {
                    c=1;
                }
                if(leaf[i]+1==in[j])
                d=1;
                if(c==1 && d==1)
                return true;
                
                
            }
        }
        return false;
        
       
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends