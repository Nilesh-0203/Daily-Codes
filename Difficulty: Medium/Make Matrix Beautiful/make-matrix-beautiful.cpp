class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int maxSum = INT_MIN;
        int n=mat.size();
        // find max sum by row wise
        for(int i=0; i<n; i++) {
            int sum1 = 0,sum2 = 0;
            for(int j=0; j<n; j++) {
               sum1 += mat[i][j];
               sum2 += mat[j][i];
            }
            maxSum = max(maxSum,max(sum1,sum2));
        }

        // now find no of oeration we have to do
        int ans = 0;
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=0; j<n; j++) {
               sum += mat[i][j]; 
            }
            ans += maxSum-sum;
        }
        return ans;
    }
};