class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int n=s1.length(),m=s2.length();
                vector<vector<int>>dp(n+1,vector<int>(m+1,0));
                for(int i=1;i<=n;i++){
                    dp[i][0]=costS1*i;
                }
                for(int j=1;j<=m;j++){
                    dp[0][j]=costS2*j;
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(s1[i-1]==s2[j-1]){
                            dp[i][j]=dp[i-1][j-1];
                        }
                        else{
                            dp[i][j]=min(costS1+dp[i-1][j],costS2+dp[i][j-1]);
                        }
                    }
                }
                return dp[n][m];
    }
};