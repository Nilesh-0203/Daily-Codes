//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     long long rec(long long start , int n,map <long long, vector <long long>> &mp,vector <vector<long long>> &dp){
      if(n==1){
          return 1;
      }
      
      if(dp[start][n] != -1){
          return dp[start][n];
      }
      
      vector <long long> v = mp[start];
      long long curr=0;
      for(int i =0  ; i < v.size() ; i++){
          curr += rec(v[i],n-1,mp,dp);
      }
      return (dp[start][n]=curr);
  }
  
    long long getCount(int n) {
        map <long long, vector <long long>> mp;
        vector <vector<long long>> dp(10,vector <long long>(n+1,-1));
        
        mp[1] = {1,2,4};
        mp[2] = {2,1,3,5};
        mp[3] = {3,2,6};
        mp[4] = {4,1,5,7};
        mp[5] = {5,2,4,6,8};
        mp[6] = {6,3,5,9};
        mp[7] = {7,8,4};
        mp[8] = {8,7,5,9,0};
        mp[9] = {9,6,8};
        mp[0] = {0,8};
        
        long long curr=0;
        for(int i =0 ; i < 10 ; i++){
            long long h = rec(i,n,mp,dp);
            curr+=h;
        }
        return curr;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends