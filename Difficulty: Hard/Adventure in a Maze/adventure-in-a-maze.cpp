class Solution {
  public:
  int MOD=1e9+7;
    int totalPaths(int r,int c,vector<vector<int>>&grid,int n, vector<vector<int>>&dp){
        if(r >= n || c >= n)return 0;
        if(r==n-1 && c==n-1)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=0;
        if(grid[r][c]==1)ans+=totalPaths(r,c+1,grid,n,dp);
        if(grid[r][c]==2)ans+=totalPaths(r+1,c,grid,n,dp);
        if(grid[r][c]==3)ans+=totalPaths(r+1,c,grid,n,dp)+totalPaths(r,c+1,grid,n,dp);
        return dp[r][c]=ans%MOD;
    }
    int maxAdventures(int r, int c,vector<vector<int>>& grid, int n,vector<vector<int>>&dp){
        if(r >= n || c >= n)return INT_MIN;
        if(r==n-1 && c==n-1)return grid[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=INT_MIN;
        if(grid[r][c]==1){
            int x=maxAdventures(r,c+1,grid,n,dp);
            if(x!=INT_MIN){
                ans=x+grid[r][c];
            }
        }
        else if(grid[r][c]==2){
            int x=maxAdventures(r+1,c,grid,n,dp);
            if(x!=INT_MIN){
                ans=x+grid[r][c];
            }
        }
        else if(grid[r][c]==3){
            int x=max(maxAdventures(r+1,c,grid,n,dp),maxAdventures(r,c+1,grid,n,dp));
            if(x!=INT_MIN){
                ans=grid[r][c]+x;
            }
        }
        return dp[r][c]=ans%MOD;
    }
    vector<int> findWays(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        int paths=totalPaths(0,0,grid,n,dp);
        int maxAdv=maxAdventures(0,0,grid,n,dp1);
        return {paths, max(0,maxAdv)};
    }
};