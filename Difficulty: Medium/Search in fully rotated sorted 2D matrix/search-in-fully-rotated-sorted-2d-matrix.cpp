class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        bool flag = false;
        vector<int> rows;
        for (int i = 0; i < n; i++) {
            sort(mat[i].begin(),mat[i].end()); //(nlogn)
            if (mat[i][0] <= x && mat[i][m - 1] >= x) {
                flag = true;
                rows.push_back(i);
            }
        }
        if (!flag) return false;
        for (int r : rows) { //[0,1]
            int start = 0, end = m - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (mat[r][mid] == x) return true;
                else if (mat[r][mid] > x) end = mid - 1;
                else start = mid + 1;
            }
        }
        return false;
    }
};
