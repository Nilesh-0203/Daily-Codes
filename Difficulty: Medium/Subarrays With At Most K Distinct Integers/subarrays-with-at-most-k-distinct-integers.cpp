class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        
        int l=0, ans=0;
        
        for (int r=0; r<arr.size(); r++) {
            mp[arr[r]]++;
            
            while (mp.size()>k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            
            ans += r-l+1;
        }
        
        return ans;
    }
};