class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // Sam
        vector<int> allSum;
        int n = arr.size();
        allSum.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            int sum = arr[i]+allSum[i-1];
            allSum.push_back(sum);
        }
        vector<int> result;
        int m = queries.size();
        for(int i=0;i<m;i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];    
            int diff = r-l+1;
            int ans = (l!=0 ? allSum[r]-allSum[l-1]:allSum[r])/diff;
            // cout<<(l!=0 ? allSum[r]-allSum[l-1]:allSum[r])<<endl;
            result.push_back(ans);
        }
        return result;
    }
};