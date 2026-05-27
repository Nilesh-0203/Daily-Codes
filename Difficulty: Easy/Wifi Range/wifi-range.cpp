class Solution {
  public:
    bool wifiRange(string &s, int x) {
        
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '1') {
                
                int left = max(0, i - x);
                int right = min(n - 1, i + x);
                
                diff[left]++;
                
                if(right + 1 < n)
                    diff[right + 1]--;
            }
        }
        
        int coverage = 0;
        
        for(int i = 0; i < n; i++) {
            
            coverage += diff[i];
            
            if(coverage <= 0)
                return false;
        }
        
        return true;
    }
};