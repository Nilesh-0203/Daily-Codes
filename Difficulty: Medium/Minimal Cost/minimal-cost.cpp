//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int ind, int k, vector<int> &arr, vector<int> &dp) {
        if(ind >= arr.size() - 1){
            return 0;
        } 
        if(dp[ind] != -1){
            return dp[ind];  
        } 
        int ans = INT_MAX;
        for(int i = 1; i <= k; ++i) {
            if(ind + i < arr.size()) {
               int temp = abs(arr[ind + i] - arr[ind]) + solve(ind + i, k, arr, dp);
                ans = min(ans, temp);
            }
        }
        return dp[ind] = ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);

        return solve(0, k, arr, dp);
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends