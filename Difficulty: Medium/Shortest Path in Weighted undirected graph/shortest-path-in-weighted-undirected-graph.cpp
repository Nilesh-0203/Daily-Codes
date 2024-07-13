//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        vector<int>dist(n+1,INT_MAX);
        vector<int>visited(n+1,0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[1]=0;
        pq.push({0,1});
        vector<int>parent(n+1,-1);
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            
            if(!visited[node]){
                visited[node]=true;
                for(auto v:adj[node]){
                    int nbr=v.first;
                    int weight=v.second;
                    if(dist[nbr]>dist[node]+weight){
                        dist[nbr]=dist[node]+weight;
                        pq.push({dist[nbr],nbr});
                        parent[nbr]=node;
                    }
                }
            }
        }
        if(parent[n]==-1){
            return {-1};
        }
        vector<int>path;
        int t=n;
        while(t!=-1){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends