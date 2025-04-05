//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int m,n;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='W'){
            return;
        }
        grid[i][j]='W';
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            dfs(grid,new_i,new_j);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='L'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends