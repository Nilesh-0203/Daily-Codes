class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 1e9; 
        for(int src = 0; src < V; src++){
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;
            q.push(src);
            dist[src] = 0;
            while(!q.empty()){
                int node = q.front(); 
                q.pop();
                for(int nbr : adj[node]){
                    if(dist[nbr] == -1) {
                        dist[nbr] = dist[node] + 1;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                    else if(parent[node] != nbr) {
                        ans = min(ans, dist[node] + dist[nbr] + 1);
                    }
                }
            }
        }
        return (ans == 1e9 ? -1 : ans);
    }
};
