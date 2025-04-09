//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,int parent,vector<int>&disc,vector<int>&low,
    unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,vector<int>&ap,int& timer){
        visited[node]=true;
        disc[node]=low[node]=timer++;
        int child=0;
        for(auto nbr:adj[node]){
            if(nbr==parent){
                continue;
            }
            
            if(!visited[nbr]){
                dfs(nbr,node,disc,low,visited,adj,ap,timer);
                low[node]=min(low[node],low[nbr]);
                
                if(low[nbr]>=disc[node] && parent!=-1){
                    ap[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }
        if(parent==-1 && child>1){
            ap[node]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer=0;
        vector<int>disc(V);
        vector<int>low(V);
        unordered_map<int,bool>visited;
        vector<int>ap(V,0);
        
        for(int i=0;i<V;i++){
            disc[i]=-1;
            low[i]=-1;
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,disc,low,visited,adj,ap,timer);
            }
        }
        vector<int>ans;
        for(int i=0;i<ap.size();i++){
            if(ap[i]!=0){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            return {-1};
        }
        return ans;
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
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends