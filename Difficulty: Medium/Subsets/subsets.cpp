//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>>result;
    void solve(int idx,vector<int>&arr,vector<int>&temp){
        if(idx>=arr.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(arr[idx]);
        solve(idx+1,arr,temp);
        temp.pop_back();
        solve(idx+1,arr,temp);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int>temp;
        solve(0,arr,temp);
        sort(result.begin(),result.end());
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the number of test cases
    while (t--) {
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(arr);

        // Print result
        for (const auto& subset : res) {
            if (subset.size() == 0) {
                cout << "[]";
            } else
                for (int num : subset) {
                    cout << num << " ";
                }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends