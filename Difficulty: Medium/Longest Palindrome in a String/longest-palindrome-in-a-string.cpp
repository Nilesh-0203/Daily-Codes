//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(string& s,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1,dp);
        }
        return dp[i][j]=false;
    }
    string longestPalindrome(string &s) {
        // code here
        int n=s.length();
        int maxLen=0;
        int sp=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)==true){
                    if(j-i+1 > maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends