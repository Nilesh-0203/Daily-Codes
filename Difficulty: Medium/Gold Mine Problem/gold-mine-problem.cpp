class Solution {
  public:
    int n,m;
    int solve(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int rightUp=mat[i][j]+solve(mat,i-1,j+1,dp);
        int right=mat[i][j]+solve(mat,i,j+1,dp);
        int rightDown=mat[i][j]+solve(mat,i+1,j+1,dp);
        
        return dp[i][j]=max(rightUp,max(right,rightDown));
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        m=mat.size(),n=mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,solve(mat,i,0,dp));
        }
        return ans;
    }
};