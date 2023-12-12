//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>&mine,vector<vector<int>>&dp,int row,int col)
    {
        if(col>=mine[0].size()) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int a=0,b=0,c=0;
        if(row-1>=0)
            a=mine[row][col]+solve(mine,dp,row-1,col+1);
        
            b=mine[row][col]+solve(mine,dp,row,col+1);
        
        if(row+1<mine.size())
            c=mine[row][col]+solve(mine,dp,row+1,col+1);
        
         return dp[row][col]=max({a,b,c});
        //  return dp[row][col];
        
    }
    int maxGold(int n, int m, vector<vector<int>> &M)
    {
        int mx=-1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            int b=solve(M,dp,i,0);
            // cout<<b<<endl;
            mx=max(mx,b);
        }
         return mx;
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