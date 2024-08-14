//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int m,n;
    int ans=0;
    int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int count=0;
        if(str1[i]==str2[j]){
            count=1+solve(str1,str2,i+1,j+1,dp);
            ans=max(ans,count);
        }
        int move1=solve(str1,str2,i+1,j,dp);
        int move2=solve(str1,str2,i,j+1,dp);
        return dp[i][j]=count;
    }
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        m=str1.length();
        n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        solve(str1,str2,0,0,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends