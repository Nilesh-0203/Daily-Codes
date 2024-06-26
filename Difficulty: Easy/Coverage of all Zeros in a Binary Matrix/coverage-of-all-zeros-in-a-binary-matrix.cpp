//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n,m;
    int find(vector<vector<int>>&matrix,int i,int j){
        int cnt=0;
        if(i-1 >=0 && matrix[i-1][j]==1){
            cnt++;
        }
        if(i+1<n && matrix[i+1][j]==1){
            cnt++;
        }
        if(j-1>=0 && matrix[i][j-1]==1){
            cnt++;
        }
        if(j+1<m && matrix[i][j+1]==1){
            cnt++;
        }
        return cnt;
    }
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        n=matrix.size();
        m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    count+=find(matrix,i,j);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends