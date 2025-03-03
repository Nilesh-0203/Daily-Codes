//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getScore(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

    vector<int> dp(n, INT_MIN);

    // Base case: score at the last index is the
    // value at that index
    dp[n - 1] = arr[n - 1];

    // Max-heap to store {dp[index], index}
    priority_queue<pair<int, int>> maxh;
    maxh.push({dp[n - 1], n - 1});

    // Iterate from second last index to the first
    for (int i = n - 2; i >= 0; i--) {

        // Remove out-of-range elements from the heap
        while (maxh.size() && maxh.top().second > i + k) {
            maxh.pop();
        }

        // Set dp[i] as the max value from the valid
        // range + current index value
        dp[i] = maxh.top().first + arr[i];

        // Push current dp[i] and index into the heap
        maxh.push({dp[i], i});
    }

    // Return the maximum score starting from the
    // first index
    return dp[0];
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
        cout << ob.getScore(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends