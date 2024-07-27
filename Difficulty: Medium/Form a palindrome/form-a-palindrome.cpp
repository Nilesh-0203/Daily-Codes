//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &str,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=str.size();
        if(str[i]==str[j]){
            ans=solve(str,i+1,j-1,dp);
        }
        ans=min({ans,1+solve(str,i+1,j,dp),1+solve(str,i,j-1,dp)});
        return dp[i][j]=ans;
    }
    int countMin(string str){
    //complete the function here
    int n=str.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return solve(str,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends