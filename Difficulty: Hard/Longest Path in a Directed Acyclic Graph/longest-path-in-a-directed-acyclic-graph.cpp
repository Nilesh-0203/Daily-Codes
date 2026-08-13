class Solution {
  public:
     void dfs(int node,vector<int> &vis,vector<vector<pair<int,int>>> &adj,stack<int> &st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int v=it.first;
            int wt=it.second;
            if(vis[v]==0)
            {
                vis[v]=1;
                dfs(v,vis,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> vis(V,0);
        stack<int> st;
        dfs(src,vis,adj,st);
        vector<int> dis(V,INT_MIN);
        dis[src]=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(top!=INT_MIN)
            {
                for(auto it:adj[top])
                {
                    int v=it.first;
                    int wt=it.second;
                    if(dis[top]+wt>dis[v])
                    {
                        dis[v]=dis[top]+wt;
                    }
                }
            }
        }
        return dis;
    }
};