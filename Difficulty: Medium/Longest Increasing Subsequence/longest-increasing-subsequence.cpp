//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n;
    int solve(vector<int>&arr,int idx,int prev,vector<vector<int>>&dp){
        if(idx>=n){
            return 0;
        }
        if(prev!=-1 && dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int take=0;
        if(prev==-1 || arr[prev]<arr[idx]){
            take=1+solve(arr,idx+1,idx,dp);
        }
        int not_take=solve(arr,idx+1,prev,dp);
        if(prev!=-1){
            dp[idx][prev]=max(take,not_take);
        }
        return max(take,not_take); 
    }
    int lis(vector<int>& arr) {
        // code here
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(arr,0,-1,dp);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends