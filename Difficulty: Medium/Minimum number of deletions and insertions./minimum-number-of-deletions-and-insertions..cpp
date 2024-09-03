//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int n,m;
	int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
	    if(i>=n || j>=m){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    if(str1[i]==str2[j]){
	        return dp[i][j]=1+solve(str1,str2,i+1,j+1,dp);
	    }
	    return dp[i][j]=max(solve(str1,str2,i+1,j,dp),solve(str1,str2,i,j+1,dp));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    n=str1.length();
	    m=str2.length();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    int res=solve(str1,str2,0,0,dp);
	    return n-res+m-res;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends