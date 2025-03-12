//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>&cost,int idx,int n,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take_one=solve(cost,idx+1,n,dp)+cost[idx];
        int take_two=solve(cost,idx+2,n,dp)+cost[idx];
        
        return dp[idx]=min(take_one,take_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(cost,0,n,dp),solve(cost,1,n,dp));
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends