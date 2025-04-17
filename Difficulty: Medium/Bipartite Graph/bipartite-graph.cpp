//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int node,vector<int>&color,unordered_map<int,vector<int>>&adj){
        color[node]=0;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto neighbor:adj[front]){
                if(color[neighbor]==-1){
                    color[neighbor]=!color[front];
                    q.push(neighbor);
                }
                else if(color[neighbor]==color[front]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(solve(i,color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            vector<int> temp;
            temp.push_back(v);
            temp.push_back(u);
            edges.push_back(temp);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends