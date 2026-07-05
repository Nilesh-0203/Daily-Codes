class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> last(26, -1);
        int n = s.length();
        int  ans = -1;
        
        for (int i=0; i<n; i++) {
            
            if (last[s[i] - 'a'] != -1) {
                ans = max(ans, i - last[s[i] - 'a']- 1);
            } else {
                last[s[i] - 'a'] = i;
            }
        }
        return ans;
    }
};