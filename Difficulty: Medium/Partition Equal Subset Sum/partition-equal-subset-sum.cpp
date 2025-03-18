//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>&arr,int idx,int currSum,int target,vector<vector<int>>&dp){
        if(idx>=arr.size()){
            return false;
        }
        if(dp[idx][currSum]!=-1){
            return dp[idx][currSum];
        }
        if(currSum>target){
            return false;
        }
        if(currSum==target){
            return true;
        }
        int take=solve(arr,idx+1,currSum+arr[idx],target,dp);
        int not_take=solve(arr,idx+1,currSum,target,dp);
        
        return dp[idx][currSum]= take || not_take;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0)return false;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return solve(arr,0,0,sum/2,dp);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends