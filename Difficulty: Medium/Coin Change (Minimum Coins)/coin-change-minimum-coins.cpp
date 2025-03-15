//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&coins,int sum,int idx,vector<vector<int>>&dp){
        if(idx>=coins.size() || sum<=0){
            return sum==0 ? 0 : INT_MAX-1;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        int ans=-1;
        if(coins[idx] > sum){
            ans=solve(coins,sum,idx+1,dp);
        }
        else{
            int take=1+solve(coins,sum-coins[idx],idx,dp);
            int not_take=solve(coins,sum,idx+1,dp);
            ans=min(take,not_take);
        }
        return dp[idx][sum]=ans;
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int res=solve(coins,sum,0,dp);
        return res==INT_MAX-1 ? -1 : res;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends