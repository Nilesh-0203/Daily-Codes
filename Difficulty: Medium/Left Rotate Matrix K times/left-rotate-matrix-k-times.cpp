//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rotateArrayTwo(int n, int r, vector < int > & num) {
        vector<int> ans(n);
        for(int i=0 ;i < num.size() ; i++)
        {
            ans[(i+n-r%n)%n] = num[i];
        }
        num=ans;
    }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            rotateArrayTwo(m,k,mat[i]);
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends