class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        int nodes=V;
        vector<int>adj[V];
        vector<int>ind(V, 0);

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ind[u]++;
            ind[v]++;
        }

        queue<int>q;
        vector<bool>vis(V, 0);

        for(int i=0; i<V; i++){
            if(ind[i]==1){
                q.push(i);
            }
        }

        while(nodes>2){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                int node=q.front();
                q.pop();
                vis[node]=true;
                nodes--;
                for(auto &ngbr:adj[node]){
                    if(!vis[ngbr]){
                        ind[ngbr]--;
                        if(ind[ngbr]==1) q.push(ngbr);
                    }
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};