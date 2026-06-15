class Solution {
  public:
    int solve(int ind, int rem, int n, vector<int>&cost, vector<vector<int>>&dp){
        if(rem==0){
            return 0;
        }
        if(ind>=n) return 1e9;
        int wt=ind+1;
        
        if(dp[ind][rem]!=-1) return dp[ind][rem];
        int ntake=solve(ind+1, rem, n, cost, dp);
        int take=1e9;
        
        if(rem>=wt && cost[ind]!=-1){
            take=cost[ind]+solve(ind, rem-wt, n, cost, dp);
        }
        return dp[ind][rem]=min(take, ntake);
    }

    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        vector<vector<int>>dp(n, vector<int>(w+1, -1));
        int ans=solve(0, w, n, cost, dp);
        return ans==1e9?-1:ans;
        
    }
};
