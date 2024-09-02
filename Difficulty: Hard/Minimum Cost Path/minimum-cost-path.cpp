//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool safe(int r,int c,int n){
        if(r>=0 && r<n && c>=0 && c<n) return true;
        else return false;
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int wt=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            
            
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                
                if(safe(newc,newr,n)&&wt+grid[newr][newc]<dist[newr][newc]){
                    dist[newr][newc]=wt+grid[newr][newc];
                    pq.push({wt+grid[newr][newc],{newr,newc}});
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends