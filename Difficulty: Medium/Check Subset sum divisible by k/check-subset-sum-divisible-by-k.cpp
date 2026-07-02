class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        if (arr.size() > k)
            return true;

        vector<bool> dp(k, false);

        for (int num : arr) {
            int rem = num % k;

            if (rem == 0)
                return true;

            vector<bool> next(dp);
            next[rem] = true;

            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    next[(r + rem) % k] = true;
                }
            }

            dp = move(next);

            if (dp[0])
                return true;
        }

        return false;
    }
};