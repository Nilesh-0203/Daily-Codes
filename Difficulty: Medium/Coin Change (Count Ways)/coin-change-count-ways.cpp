//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&coins,int sum,int idx,vector<vector<int>>&dp){
        if(idx>=coins.size() || sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        dp[idx][sum]=solve(coins,sum-coins[idx],idx,dp)+solve(coins,sum,idx+1,dp);
        return dp[idx][sum];
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int res=solve(coins,sum,0,dp);
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends