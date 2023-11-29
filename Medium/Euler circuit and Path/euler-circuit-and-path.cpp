//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEulerCircuit(int v, vector<int>adj[]){
        if (v == NULL){
            return {};
        }
        
        int circuit = 0;
        int path = 0;
        
        for (int i=0; i<v; i++){
            if (adj[i].size()%2 == 0){
                circuit++;
            }
            else{
                path++;
            }
        }
        
        if (circuit == v){
            return 2;
        }
        else if(path == 2){
             return 1;
        }
        else{
            return 0;
        }
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends