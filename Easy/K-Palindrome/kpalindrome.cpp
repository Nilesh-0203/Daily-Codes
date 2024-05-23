//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int lcs(string &str,string &rev,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==rev[j]){
            return dp[i][j]=1+lcs(str,rev,i-1,j-1,dp);
        }
        return dp[i][j]=max(lcs(str,rev,i,j-1,dp),lcs(str,rev,i-1,j,dp));
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string rev=str;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int m=lcs(str,rev,n-1,n-1,dp);
        int rem=n-m;
        return rem<=k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends