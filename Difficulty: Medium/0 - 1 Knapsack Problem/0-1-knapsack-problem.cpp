//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int solve(int W, vector<int> &val, vector<int> &wt,int idx,vector<vector<int>>&dp){
        if(idx>=n){
            return 0;
        }
        if(W<0){
            return 0;
        }
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }
        int take=0;
        if(wt[idx]<=W){
            take=val[idx]+solve(W-wt[idx],val,wt,idx+1,dp);
        }
        int not_take=solve(W,val,wt,idx+1,dp);
        
        return dp[idx][W]=max(take,not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(W,val,wt,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends