class Solution {
  public:
    bool isPalindrome(string &s, int left, int right) {
        
        while(left < right) {
            
            if(s[left] != s[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        
        unordered_map<string, int> mp;
        
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            
            string word = arr[i];
            int n = word.length();
            
            for(int j = 0; j <= n; j++) {
                
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                if(isPalindrome(word, 0, j - 1)) {
                    
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    
                    if(mp.count(revRight) && mp[revRight] != i) {
                        return true;
                    }
                }
                
                if(j != n && isPalindrome(word, j, n - 1)) {
                    
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    
                    if(mp.count(revLeft) && mp[revLeft] != i) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};