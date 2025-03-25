//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int solve(int i, int j, bool isT, string &s, 
    vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        else if(i==j){
            if(isT) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][isT]!=-1) return dp[i][j][isT];
        
        int ways=0;
        
        for(int ind=i+1; ind<=j-1; ind+=2){
            int lT=solve(i, ind-1, 1, s, dp);
            int lF=solve(i, ind-1, 0, s, dp);
            int rT=solve(ind+1, j, 1, s, dp);
            int rF=solve(ind+1, j, 0, s, dp);
            
            if(isT){
                if(s[ind]=='&'){
                    ways+=(lT*rT);
                }else if(s[ind]=='|'){
                    ways+=((lT*rT)+(lT*rF)+(lF*rT));
                }else{
                    ways+=((lT*rF)+(lF*rT));
                }
            }else{
                if(s[ind]=='&'){
                    ways+=((lF*rF)+(lT*rF)+(lF*rT));
                }else if(s[ind]=='|'){
                    ways+=(lF*rF);
                }else{
                    ways+=((lT*rT)+(lF*rF));
                }
            }
        }
        return dp[i][j][isT]=ways;
    }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n-1, 1, s, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends