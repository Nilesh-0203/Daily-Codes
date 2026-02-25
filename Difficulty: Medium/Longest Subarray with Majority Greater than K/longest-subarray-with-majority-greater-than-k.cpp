class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size(), ans = 0, ct = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            if(arr[i]>k) ct++;
            else ct--;
            
            if(ct > 0) ans = max(ans, i+1);
            else if(mp.find(ct-1)!=mp.end()) ans = max(ans, i-mp[ct-1]);
            
            if(mp.find(ct)==mp.end()) mp[ct]=i;
        }
        return ans;
    }
};