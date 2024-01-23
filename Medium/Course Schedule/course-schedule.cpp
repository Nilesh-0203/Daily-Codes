//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> inDegree(n, 0);
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<m; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        bool found = false;
        for(int i=0; i<n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                found = true;
            }
        }
        
        if(!found) {
            return ans;
        }
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto nbr: adj[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        if(ans.size() != n) {
            return {};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends