//{ Driver Code Starts

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
    int count = 0;

    // Store the frequency of sum of first two elements
    unordered_map<int, int> freq;

    // Traverse from 0 to n-1, where arr[i] 
    // is the 3rd element
    for (int i = 0; i < n - 1; i++) {

        // All possible 4th elements
        for (int j = i + 1; j < n; j++) {

            // Sum of last two elements
            int temp = arr[i] + arr[j];

            // Check for valid sum of the first two elements
            count += freq[target - temp];
        }

        // Store frequency of all possible sums 
        // of first two elements
        for (int j = 0; j < i; j++) {
            int temp = arr[i] + arr[j];
            freq[temp]++;
        }
    }
  
    return count;
        
    }

};

//{ Driver Code Starts.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t-- > 0) {
        string input;
        getline(std::cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline character after reading k

        Solution solution;
        int ans = solution.countSum(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends