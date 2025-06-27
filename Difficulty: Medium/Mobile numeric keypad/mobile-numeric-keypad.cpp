class Solution {
  public:
    vector<vector<int>> adj{{0,8},{1,2,4},{2,1,3,5},{3,2,6},{4,1,5,7},{5,2,4,6,8},{6,3,5,9},{7,4,8},{8,0,5,7,9},{9,6,8}};
     long long solve(int n,int cell,vector<vector<long long>>&dp){
        if(n==1){
            return 1;
        }
          
        if(dp[n][cell] != -1){
            return dp[n][cell];
        }
        long long ans=0;
        for(int &next:adj[cell]){
            ans=(ans+solve(n-1,next,dp));
        }
        return dp[n][cell]=ans;
     }
    int getCount(int n) {
        // code here
        vector <vector<long long>> dp(n+1,vector <long long>(10,-1));
        long long res=0;
        for(int i =0 ; i < 10 ; i++){
            long long h = solve(n,i,dp);
            res+=h;
        }
        return res;
    }
};