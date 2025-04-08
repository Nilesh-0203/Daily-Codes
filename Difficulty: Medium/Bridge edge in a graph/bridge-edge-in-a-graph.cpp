//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int node){
        visited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(adj,visited,neighbor);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        unordered_map<int,list<int>>adj1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        unordered_map<int,list<int>>adj2;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            if((u==c && v==d) || (u==d && v==c)){
                continue;
            }
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        
        int count1=0;
        unordered_map<int,bool>visited1;
        for(int i=0;i<V;i++){
            if(!visited1[i]){
                count1++;
                dfs(adj1,visited1,i);
            }
        }
        int count2=0;
        unordered_map<int,bool>visited2;
        for(int i=0;i<V;i++){
            if(!visited2[i]){
                count2++;
                dfs(adj2,visited2,i);
            }
        }
        return count1!=count2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends