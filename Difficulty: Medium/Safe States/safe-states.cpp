class Solution {
  public:
    vector<vector<int>> GetAdj(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        return adj;
    }
    bool dfs(int V, vector<vector<int>> &adj, vector<int>& dp){
        if(dp[V] != -1){
            return bool(dp[V]);
        }
        
        dp[V] = 0;
        for(int neigh: adj[V]){
            bool isTrue = dfs(neigh, adj, dp);
            if(!isTrue){
                return false;
            }
        }
        
        dp[V] = 1;
        return true;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = GetAdj(V, edges);
        vector<int> dp(V, -1);
        for(int node = 0;node<V;node++){
            dfs(node, adj, dp);
        }
        vector<int> safe;
        for(int i = 0;i<V; i++){
            if(dp[i] == 1){
                safe.push_back(i);
            }
        }
        return safe;
    }
};