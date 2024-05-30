//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=(solve(i-1,j-1,s1,s2,dp)%mod+solve(i-1,j,s1,s2,dp)%mod)%mod;
        }
        else{
            return dp[i][j]=solve(i-1,j,s1,s2,dp)%mod;
        }
    }
    int countWays(string s1, string s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        if(m>n){
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends