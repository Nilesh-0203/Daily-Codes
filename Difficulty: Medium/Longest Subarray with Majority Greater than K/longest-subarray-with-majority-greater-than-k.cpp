//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
    unordered_map<int, int> prefIdx;
    int sum = 0, res = 0;

    // Traverse through all subarrays
    for (int i = 0; i < n; i++) {

        // Consider arr[i] <= k as -1 and arr[i] > k as +1
        sum += (arr[i] > k ? 1 : -1);

        // make an entry for sum if it is not present
        // in the hash map
        if (prefIdx.find(sum) == prefIdx.end())
            prefIdx[sum] = i;
    }
  
    // If all elements are smaller than k, return 0
    if(prefIdx.find(-n) != prefIdx.end())
        return 0;
  
    prefIdx[-n] = n;
  
    // For each sum i, update prefIdx[i] with 
    // min(prefIdx[-n], prefIdx[-n+1] .... pref[i])
    for(int i = -n + 1; i <= n; i++) {
        if(prefIdx.find(i) == prefIdx.end())
            prefIdx[i] = prefIdx[i - 1];
        else
            prefIdx[i] = min(prefIdx[i], prefIdx[i - 1]);
    }
    
    // To find the longest subarray with sum > 0 ending at i,
    // we need left-most occurrence of s' such that s' < s.
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (arr[i] > k ? 1 : -1);
        if(sum > 0)
            res = i + 1;
        else
            res = max(res, i - prefIdx[sum - 1]);
    }
    return res;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends