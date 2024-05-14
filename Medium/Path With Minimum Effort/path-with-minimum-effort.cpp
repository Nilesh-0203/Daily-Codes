//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
       vector<vector<int>>dp(rows,vector<int>(columns,1000000000));
        dp[0][0] = 0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
        q.push({0,0});
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int x = p.first,y = p.second;
            for(auto it:dir){
                int i = x + it.first,j = y + it.second;
                if(i<0 || j<0 || i>=rows || j>=columns)continue;
                if(dp[i][j]>max(abs(heights[i][j]-heights[x][y]),dp[x][y])){
                    dp[i][j]=max(abs(heights[i][j]-heights[x][y]),dp[x][y]);
                    q.push({i,j});
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends