//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createMap(int in[],map<int,vector<int>>&mp,int n){
        for(int i=0;i<n;i++){
            mp[in[i]].push_back(i);
        }
        for(auto &it:mp){
            reverse(it.second.begin(),it.second.end());
        }
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,vector<int>>&mp){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int position=mp[element].back();
        mp[element].pop_back();
        
        root->left=solve(in,pre,index,inorderStart,position-1,n,mp);
        root->right=solve(in,pre,index,position+1,inorderEnd,n,mp);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex=0;
        map<int,vector<int>>mp;
        createMap(in,mp,n);
        Node* ans=solve(in,pre,preOrderIndex,0,n-1,n,mp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends