class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        
        int max_sum = INT_MIN;
        
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int total = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
                max_sum = max(max_sum, total);
            }
        }
        
        return max_sum;
    }
};