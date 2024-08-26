//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int Solve(string &ptr,string &str,vector<vector<int>>&dp,int i,int j){
      if(i>=ptr.size() && j>=str.size())
      return 1;
      if(i>=ptr.size() && j<str.size())
      return 0;
      if(i<ptr.size() && j>=str.size()){
          for(int k=ptr.size()-1;k>=i;k--){
              if(ptr[k]!='*'){
                  return 0;
              }
          }
          return 1;
      }
      if(dp[i][j]!=-1)
      return dp[i][j];
      int ans=0;
      if(ptr[i]==str[j] || ptr[i]=='?')
      ans=Solve(ptr,str,dp,i+1,j+1);
      else if(ptr[i]=='*')
          ans=Solve(ptr,str,dp,i+1,j) || Solve(ptr,str,dp,i,j+1);
    
      return dp[i][j]=ans;
  }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return Solve(pattern,str,dp,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends