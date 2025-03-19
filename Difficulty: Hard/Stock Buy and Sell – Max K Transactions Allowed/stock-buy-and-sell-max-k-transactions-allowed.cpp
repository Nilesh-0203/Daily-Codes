//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n;
    int solve(vector<int>&prices,int idx,bool buy,int limit,vector<vector<vector<int>>>&dp){
        if(idx>=n){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[idx][buy][limit]!=-1){
            return dp[idx][buy][limit];
        }
        int profit=0;
        if(buy){
            int buy_karo=-prices[idx]+solve(prices,idx+1,!buy,limit,dp);
            int skip_karo=solve(prices,idx+1,buy,limit,dp);
            profit=max(buy_karo,skip_karo);
        }
        else{
            int sell_karo=prices[idx]+solve(prices,idx+1,!buy,limit-1,dp);
            int skip_karo=solve(prices,idx+1,buy,limit,dp);
            profit=max(sell_karo,skip_karo);
        }
        return dp[idx][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,true,k,dp);
    }
};




//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends