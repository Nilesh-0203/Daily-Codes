//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        set<pair<int,int>>st;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        
        st.insert({0,src});
        
        while(!st.empty()){
            auto top=*(st.begin());
            int nodedistance=top.first;
            int topnode=top.second;
            st.erase(st.begin());
            
            for(auto neighbor:adj[topnode]){
                if(nodedistance+neighbor.second < dist[neighbor.first]){
                    auto record=st.find(make_pair(dist[neighbor.first],neighbor.first));
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    dist[neighbor.first]=nodedistance+neighbor.second;
                    st.insert({dist[neighbor.first],neighbor.first});
                }
            }
        }
        return dist; 
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends