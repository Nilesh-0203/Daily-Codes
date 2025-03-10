//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to compute the edit distance between two strings
    int n1,n2;
    int solve(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
        if(i>=n1){
            return n2-j;
        }
        if(j>=n2){
            return n1-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=solve(s1,s2,i+1,j+1,dp); 
        }
        else{
            int insert=1+solve(s1,s2,i,j+1,dp);
            int Delete=1+solve(s1,s2,i+1,j,dp);
            int replace=1+solve(s1,s2,i+1,j+1,dp);
            ans=min(insert,min(Delete,replace));
        }
        return dp[i][j]=ans;
    }
    int editDistance(string& s1, string& s2) {
        // code here
        n1=s1.length();
        n2=s2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s1,s2,0,0,dp);
    }
};




//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends