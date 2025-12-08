class Solution {
  public:
    string solve(int i, int j, vector<vector<int>> &br) {
        if (i == j) return string(1, 'A' + i - 1);
        int k = br[i][j];
        return "(" + solve(i, k, br) + solve(k + 1, j, br) + ")";
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1;

        vector<vector<long long>> dp(m + 2, vector<long long>(m + 2, 0));
        vector<vector<int>> br(m + 2, vector<int>(m + 2, 0));

        for (int len = 2; len <= m; len++) {
            for (int i = 1; i + len - 1 <= m; i++) {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k + 1][j] +
                                     (long long)arr[i - 1] * arr[k] * arr[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        br[i][j] = k;
                    }
                }
            }
        }

        return solve(1, m, br);
    }
};