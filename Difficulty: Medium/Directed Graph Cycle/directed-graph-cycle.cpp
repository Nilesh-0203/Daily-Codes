//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool dfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,int node){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                bool cycle=dfs(adj,visited,dfsVisited,neighbor);
                if(cycle){
                    return true;
                }
            }
            else if(dfsVisited[neighbor]==true){
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle=dfs(adj,visited,dfsVisited,i);
                if(cycle){
                    return true;
                }
            }
        }
        return false;
    }
};




//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends