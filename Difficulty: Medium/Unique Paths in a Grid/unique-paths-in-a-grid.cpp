class Solution {
  public:
    int m,n;
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n || grid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(grid,i,j+1,dp);
        int down=solve(grid,i+1,j,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
};