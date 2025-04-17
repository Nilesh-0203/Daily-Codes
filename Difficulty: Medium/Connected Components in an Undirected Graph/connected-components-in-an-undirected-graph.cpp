//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void dfs(unordered_map<int,list<int>>&adj,vector<bool>&visited,int node,vector<int>&v){
        visited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                v.push_back(neighbor);
                dfs(adj,visited,neighbor,v);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>ans;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>v;
                v.push_back(i);
                dfs(adj,visited,i,v);
                sort(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
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
        vector<vector<int>> res = obj.getComponents(V, edges);

        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends