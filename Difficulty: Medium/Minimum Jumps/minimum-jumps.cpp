//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int solve(vector<int>&arr,int idx,vector<int>&dp){
        if(idx>=(n-1)){
            return 0;
        }
        if(arr[idx]==0){
            return 1e7;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=1e7;
        for(int i=idx+1;i<=idx+arr[idx];i++){
            ans=min(ans,1+solve(arr,i,dp));
        }
        return dp[idx]=ans;
    }
    int minJumps(vector<int>& arr) {
        // code here
        n=arr.size();
        vector<int>dp(n+1,-1);
        int res=solve(arr,0,dp);
        return res==1e7 ? -1 : res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends