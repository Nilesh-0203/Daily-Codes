//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        int n = arr.size(), res = 0;
        unordered_map<int, int> prefCnt;
        int sum = 0;
      
        // Iterate over all ending points
        for(int i = 0; i < n; i++) {
          
            // prefix sum mod k (handling negative prefix sum)
            sum = ((sum + arr[i]) % k + k) % k;
          
            // If sum == 0, then increment the result by 1
            // to count subarray arr[0...i]
            if(sum == 0)
                res += 1;
          
            // Add count of all starting points for index i
            res += prefCnt[sum];
          
            prefCnt[sum] += 1;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d
        Solution ob;
        cout << ob.subCount(arr, d);
        cout << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends