//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int curr_ind, vector<int>& arr, int isUp,vector<vector<int>>&dp) {
    if (curr_ind == 0) return 1;
    
    if(dp[curr_ind][isUp] != -1){
        return dp[curr_ind][isUp];
    }
    int nottake = f(curr_ind - 1, arr, isUp,dp);
    int take = 0;
    if (isUp) {
        if (arr[curr_ind] > arr[curr_ind - 1]) {
            take = 1 + f(curr_ind - 1, arr, 0,dp);
        }
    } else {
        if (arr[curr_ind] < arr[curr_ind - 1]) {
            take = 1 + f(curr_ind - 1, arr, 1,dp);
        }
    }
    return dp[curr_ind][isUp]=max(take, nottake);
}

int alternatingMaxLength(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return max(f(n - 1, arr, 1,dp), f(n - 1, arr, 0,dp));
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends