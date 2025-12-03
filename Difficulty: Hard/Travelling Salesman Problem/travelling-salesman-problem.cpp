class Solution {
  public:
    int n;
    int solve(int pos, int mask, vector<vector<int>>& cost, vector <vector <int>>& dp){
        if(mask == (1 << n) - 1) return cost[pos][0];
        if(dp[mask][pos] != -1) return dp[mask][pos];
        
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if(!((1 << i) & mask)){
                res = min(res, cost[pos][i] + solve(i, (mask | (1 << i)), cost, dp));
            }
        }
        
        return dp[mask][pos] = res;
    }
  
    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        vector <vector <int>> dp((1 << n), vector <int> (n, -1));
        return solve(0, 1, cost, dp);
    }
};