//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
      if (s1.length() != s2.length()) {
        return false;
    }
    
    // Construct the temporary string
    string temp = s2 + "$" + s1 + s1;
    int n = temp.length();
    
    // Initialize the LPS (Longest Prefix Suffix) array
    vector<int> arr(n, 0);
    int i = 1;
    int len = 0;

    // Build the LPS array
    while (i < n) {
        if (temp[i] == temp[len]) {
            len++;
            arr[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = arr[len - 1];
            } else {
                i++;
            }
        }
    }

    // Check if the length of `s1` appears in the LPS array
    for (int a : arr) {
        if (a == s1.length()) {
            return true;
        }
    }
    return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends