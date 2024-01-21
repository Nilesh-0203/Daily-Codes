//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
         int check(vector<int>adj[],vector<bool>visited,int i,int count,int k,int n)
    {
        if(count>k)
        return 10000;
        if(count==k)
        {
            return 0;
        }
        if(i>n)
        return 10000;
        int nottake=0+check(adj,visited,i+1,count,k,n);
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                count++;
            }
        }
        visited[i]=true;
       
       int take=1+check(adj,visited,i+1,count,k,n);
        return min(take,nottake);
    }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                 int V=n+1;
                vector<int>adj[V];
                for(int i=0;i<edges.size();i++)
                {
                    adj[edges[i].first].push_back(edges[i].second);
                    adj[edges[i].second].push_back(edges[i].first);
                }
                
                vector<bool>visited(n+1,false);
             
                return check(adj,visited,1,0,edges.size(),n);
              
            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends