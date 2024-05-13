//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
     int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int g =0;
        vector<vector<int>> adj(v);
        unordered_map<int,int> vis;
        for(int i =0;i< e;i++){
            int a =edges[i][0];
            int b =edges[i][1];
            --a;--b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int a =0,b =0;
        int edge =0;
        for(int i =0;i< v;i++){
            if(vis.find(i) == vis.end()){
                edge =0;
                b =vis.size();
                dfs(adj,vis,edge,i,-1);
                a = vis.size() -b;
                // cout<<a<<" "<<edge<<endl;
                if(edge/2 == a*(a -1)/2){
                    g++;
                }
            }
        }
        return g;
    }
    
    void dfs(vector<vector<int>> &adj,unordered_map<int,int> &vis,int& edge,int src,int par){
        vis[src]=1;
        for(auto a: adj[src]){
            if(vis.find(a) == vis.end()){
                edge++;
                dfs(adj,vis,edge,a,src);
            }
            else if(src != par){
                edge++;
            }
        }
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends