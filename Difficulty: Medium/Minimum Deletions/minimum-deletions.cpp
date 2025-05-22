class Solution {
  public:
    int minDeletions(string S) {
        // code here
         int n = S.size();
        string R =  string(S.rbegin(), S.rend()); // string reverese.
        
        int dp[n+1][n+1] = {}; // To initialize first row and column to '0'
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(S[i] == R[j])
                {
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        
        return n-dp[n][n];
    }
};