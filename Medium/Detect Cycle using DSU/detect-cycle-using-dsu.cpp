//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	void make_set(int v,vector<int>&parent,vector<int>&size){
        parent[v]=v;
        size[v]=1;
    }
    int find_set(int v,vector<int>&parent,vector<int>&size){
        if(v==parent[v]) return v;
        return parent[v]=find_set(parent[v],parent,size);
    }
    void union_set(int a,int b,vector<int>&parent,vector<int>&size){
        a=find_set(a,parent,size);
        b=find_set(b,parent,size);
        
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            
            parent[b]=a;
            size[a]+size[b];
        }
    }
    int detectCycle(int V, vector<int>adj[])
    {
        // Code here
        vector<int>parent(V);
        vector<int>size(V);
        
        for(int i=0;i<V;i++){
            make_set(i,parent,size);
        }
        
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                int x=find_set(i,parent,size);
                int y=find_set(j,parent,size);
                
                if(x==y && i<j) return 1;
                else union_set(i,j,parent,size);
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends