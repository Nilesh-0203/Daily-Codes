//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {0, 0})); // {horizontal, vertical}
        
        // count horizontal x
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 'X')
                    x++;
                else 
                    x = 0;
                    
                dp[i][j].first = x;
            }
        }
        
        // count vertical x
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = 0; j < n; j++) {
                if(a[j][i] == 'X')
                    x++;
                else
                    x = 0;
                    
                dp[j][i].second = x;
            }
        }
        
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int mini = min(dp[i][j].first, dp[i][j].second);
                
                while(mini > 0) {
                    int x = j - mini + 1, y = i - mini + 1;
                        
                    if(x >= 0 and x < n and y >= 0 and y < n) {
                        if(dp[i][x].second >= mini and dp[y][j].first >= mini) {
                            maxi = max(maxi, mini); 
                            break;
                        }
                    }
                    
                    mini--;
                }
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends