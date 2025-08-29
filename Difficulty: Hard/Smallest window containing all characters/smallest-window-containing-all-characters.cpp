class Solution {
  public:
    string smallestWindow(string &s, string &t) {
        // code here
        if (s.length() < t.length()) return "";
        
        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, minStart = 0, minLen = INT_MAX;
        
        for (char c : t) map[c]++;
        
        for (int end = 0; end < s.length(); end++) {
            if (map[s[end]]-- > 0) count--;
            
            while (count == 0) {
                if (end - start + 1 < minLen) {
                    minStart = start;
                    minLen = end - start + 1;
                }
                
                if (map[s[start++]]++ == 0) count++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};