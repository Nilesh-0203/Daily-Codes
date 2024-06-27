//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int cntFreshOrange=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    cntFreshOrange++;
                }
            }
        }
        if(cntFreshOrange==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int min=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                pair<int,int>temp=q.front();
                int i=temp.first;
                int j=temp.second;
                q.pop();
                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        q.push(make_pair(new_i,new_j));
                        cntFreshOrange--;
                    }
                }
            }
            min++;
        }
        if(cntFreshOrange!=0){
            return -1;
        }
        return min-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends