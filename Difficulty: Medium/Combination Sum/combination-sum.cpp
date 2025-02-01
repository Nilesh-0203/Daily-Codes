//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>&arr,int sum,int target,int idx){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            temp.push_back(arr[i]);
            sum=sum+arr[i];
            solve(ans,temp,arr,sum,target,i);
            temp.pop_back();
            sum=sum-arr[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,arr,0,target,0);
        return ans;
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
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends