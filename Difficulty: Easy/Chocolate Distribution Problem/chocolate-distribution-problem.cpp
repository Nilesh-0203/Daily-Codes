class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin() , a.end());
        int j = 0;
        int mini = INT_MAX;
        for(int i=m-1;i<n;i++){
            mini = min(mini , a[i] - a[j]);
            j++;
        }
        return mini;
    }
};