//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        int n = arr.size(), res = 0;
        unordered_map<int, int> prefIdx;
        int sum = 0;
    
        // Iterate over all ending points
        for (int i = 0; i < n; i++) {
    
            // prefix sum mod k (handling negative prefix sum)
            sum = ((sum + arr[i]) % k + k) % k;
    
            // If sum == 0, then update result with the
            // length of subarray arr[0...i]
            if (sum == 0)
                res = i + 1;
    
            // Update max length for repeating sum
            else if (prefIdx.find(sum) != prefIdx.end()) {
                res = max(res, i - prefIdx[sum]);
            }
    
            // Store the first occurrence of sum
            else {
                prefIdx[sum] = i;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.longestSubarrayDivK(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends