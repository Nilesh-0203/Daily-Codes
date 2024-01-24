//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
     bool isCycle(int node, int par, vector<bool> &visited, vector<int> parents, const vector<vector<int>> &adj)
    {
        visited[node] = true;
    
        for(auto v: adj[node])
        {
            if(v == par)
                continue;
            
            if(visited[v] && v != par)
                return true;
            
            parents[v] = node;
            
            if(isCycle(v, parents[v], visited, parents, adj))
                return true;
        }
        return false;
    }
    
    int isTree(int n, int m, vector<vector<int>> &graph)
    {
        vector<vector<int>> adj(n);
        
        //Making an adjacency list out of the input. I have changed the argument name for the making the list with name adj
        for(auto it : graph)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        

    
        vector<bool> visited(n, false);
        vector<int> parents(n, -1);
        
        
        //checking for cycle
        if(isCycle(0, parents[0], visited, parents, adj))
                return false;

        //if all the nodes are visited, that means that they are all connected else we will return false
        for (int i = 0; i < n; i++)
        {
            if(!visited[i])
                return false;
        }
    
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends