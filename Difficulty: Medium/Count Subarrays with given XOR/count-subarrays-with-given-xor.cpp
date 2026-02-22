class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long ct = 0;
        int c = 0;
        unordered_map<int, int> mp;
        mp.reserve(arr.size()); 
        mp[0] = 1;              

        for (const int& it : arr) {
            c ^= it;
            ct += mp[c ^ k];    
            mp[c]++;
        }

        return ct;
    }
};