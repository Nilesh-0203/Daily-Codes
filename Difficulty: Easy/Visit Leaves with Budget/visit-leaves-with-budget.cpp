/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    vector<int> v;
void solve(int count,Node *root)
{
    if(root==NULL)
    {
        return;
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        v.push_back(count);
    }
    solve(count+1,root->left);
    solve(count+1,root->right);
}
    int getCount(Node *root, int k)
    {
        //code here
        solve(1,root);
        
        sort(v.begin(),v.end());
        
        int sum=0,c=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum>k)
            {
                break;
            }
            c++;
        }
        return c;
    }
};
