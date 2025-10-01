class Solution {
  public:
    void solve(set<vector<int>> &sv, vector<int> arr, int ind, int n) {
        // base case
        if(ind == n) {
            sv.insert(arr);
            return ;
        }
        
        for(int j = ind;j < n; j++) {
            swap(arr[ind], arr[j]);
            solve(sv, arr, ind+1, n);  // recursive case
            swap(arr[ind], arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n=arr.size();
        set<vector<int>> sv;
        solve(sv, arr, 0, n);

        vector<vector<int>> ans(sv.begin(), sv.end());
        return ans;
    }
};