class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
         int mx_curr = 0, mxsum = -1e9;
        int mn_curr = 0, mnsum = 1e9;
        int n = arr.size(), total = 0;
        for(int i=0; i<n; i++){
            total += arr[i];
            mx_curr += arr[i];
            mn_curr += arr[i];
            mxsum = max(mxsum, mx_curr);
            mnsum = min(mnsum, mn_curr);
            if(mx_curr < 0){
                mx_curr = 0;
            }
            if(mn_curr > 0){
                mn_curr = 0;
            }
        }
        
        if(total == mnsum){
            return mxsum;
        }
        
        return max(mxsum, total-mnsum);
    }
};