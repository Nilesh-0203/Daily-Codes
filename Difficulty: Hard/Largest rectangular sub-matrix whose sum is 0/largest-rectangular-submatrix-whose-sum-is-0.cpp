//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxZeroSumSubarray(vector<int> &arr) {
    int prefSum = 0;
      int maxLength = 0;

    // Hash map to store the first index of each prefix sum
    unordered_map<int, int> mp;

    // Iterate through the array to find subarrays with zero sum
    for (int i = 0; i < arr.size(); i++) {
        prefSum += arr[i];
      
          if (prefSum == 0) 
              maxLength = i+1;

        if (mp.find(prefSum) != mp.end()) {
            // If this prefSum repeats, find subarray length.
            maxLength = max(maxLength, (i - mp[prefSum]));
        }
        else {
            // Only store the index of the first occurrence of prefSum
            mp[prefSum] = i;
        }
    }

    return maxLength;
}

int zeroSumSubmat(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
      
        // Temporary array to store the column-wise cumulative sum
        vector<int> temp(cols, 0);

        // Iterate over each row from i to j
        for (int j = i; j < rows; j++) {
          
            // Accumulate the column-wise sum for rows between i and j
            for (int k = 0; k < cols; k++)
                temp[k] += mat[j][k];

            // Find the longest zero-sum subarray in column sums
            int len = maxZeroSumSubarray(temp);

            // Update the maximum area 
            maxArea = max(maxArea, (j - i + 1) * len);
        }
    }

    return maxArea;
 }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.zeroSumSubmat(mat);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends