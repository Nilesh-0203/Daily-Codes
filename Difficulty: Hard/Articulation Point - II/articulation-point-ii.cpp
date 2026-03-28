class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(V, -1), low(V), ap(V, 0);
        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int parent) {
            tin[u] = low[u] = timer++;
            int children = 0;

            for (int v : adj[u]) {
                if (v == parent) continue;
                if (tin[v] == -1) {
                    children++;
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (parent != -1 && low[v] >= tin[u])  ap[u] = 1;
                } 
                else  low[u] = min(low[u], tin[v]);
            }
            if (parent == -1 && children > 1) ap[u] = 1;
        };

        for (int i = 0; i < V; i++) if(tin[i] == -1) dfs(i, -1);
        
        vector<int> ans;
        for (int i = 0; i < V; i++) if(ap[i]) ans.push_back(i);
        
        return ans.empty() ? vector<int>{-1} : ans;
    }
};