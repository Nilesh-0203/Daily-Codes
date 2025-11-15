class Solution {
  public:
    int dp[103][103];
    int solve(vector<int>& cuts,int l,int r){
        if(r-l<2){
            return 0;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MAX;
        for(int i=l+1;i<=r-1;i++){
            int cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
            ans=min(ans,cost);
        }
        return dp[l][r]= ans;
    }
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        sort(cuts.begin(),cuts.end());
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        memset(dp,-1,sizeof(dp));
        return solve(cuts,0,cuts.size()-1);
    }
};