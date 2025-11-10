class Solution {
  public:
    int solve(int i, int n, int s, vector<int>&arr, vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][s]!=-1) return dp[i][s];
        
        int buy=0, sell=0;
        
        if(s==0){
            buy=max(solve(i+1, n, s, arr, dp), (-1)*arr[i]+solve(i+1, n, 1-s, arr, dp));
        }else{
            sell=max(solve(i+1, n, s, arr, dp), arr[i]+solve(i+2, n, 1-s, arr, dp));
        }
        
        return dp[i][s]=max(buy, sell);
        
    }
  
    int maxProfit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, n, 0, arr, dp);
    }
};