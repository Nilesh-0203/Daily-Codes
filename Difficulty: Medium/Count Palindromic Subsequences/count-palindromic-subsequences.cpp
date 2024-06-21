//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int solve(string &s,vector<vector<long long int>>&dp,int i,int j){
        int mod=1e9+7;
        if(i==j){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            dp[i][j]=(1+solve(s,dp,i+1,j)+ solve(s,dp,i,j-1))%mod;
        }
        else{
            dp[i][j]=((solve(s,dp,i+1,j)+solve(s,dp,i,j-1)-solve(s,dp,i+1,j-1))%mod+mod)%mod;
        }
        return dp[i][j];
    }
    long long int  countPS(string s)
    {
       //Your code here
       int n=s.length();
       vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
       return solve(s,dp,0,n-1);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends