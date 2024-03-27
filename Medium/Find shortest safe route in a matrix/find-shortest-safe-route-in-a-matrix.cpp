//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     vector<vector<int>> dp;
    bool check(int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        if(mat[i][j] == 0) return 0;
        if(i+1 < n && mat[i+1][j] == 0) return 0;
        if(i-1 >=0 && mat[i-1][j] == 0) return 0;
        if(j+1 < m && mat[i][j+1] == 0) return 0;
        if(j-1 >=0 && mat[i][j-1] == 0) return 0;
        return 1;
    }
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis)
    {
        int n = mat.size(), m = mat[0].size();
        if(j == m-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        vis[i][j] = 1;
        
        int dr[] = {0,1,0,-1};
        int dc[] = {-1,0,1,0};
        int ans = 1e9;
        for(int ind = 0; ind<4; ind++)
        {
            int newi = i + dr[ind];
            int newj = j + dc[ind];
            
            if(newi < n && newi >=0 && newj < m && newj >=0 && 
            check(newi, newj, mat) && !vis[newi][newj])
            {
                int temp = 1 + solve(newi, newj, mat, vis);
                ans = min(ans, temp);
            }
            
        }
        vis[i][j] = 0;
        
        return dp[i][j]=ans;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
       int n = mat.size(), m = mat[0].size();
       dp = vector<vector<int>> (n, vector<int> (m, -1));
       vector<vector<int>> vis(n, vector<int> (m ,0 ));
       int ans = 1e9;
      for(int i=0; i<n; i++)
      {
          if(check(i,0, mat))
          {
            ans = min(ans, solve(i, 0, mat, vis));
          }
          
      }
       if(ans == 1e9) return -1;
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends