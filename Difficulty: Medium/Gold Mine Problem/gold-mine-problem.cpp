//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N,M;
    int solve(vector<vector<int>>&mine,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=N || j>=M){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=mine[i][j]+solve(mine,i,j+1,dp);
        int rightUp=mine[i][j]+solve(mine,i-1,j+1,dp);
        int rightDown=mine[i][j]+solve(mine,i+1,j+1,dp);
    
        return dp[i][j]=max(right,max(rightUp,rightDown));
    }
    int maxGold(int n, int m, vector<vector<int>> mine)
    {
        // code here
        int ans=0;
        N=n,M=m;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(mine,i,0,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends