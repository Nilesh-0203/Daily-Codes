class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int maxLength = 1;
        int i = 0;
        int tk = k;
        for(int g = 0; g<26; g++){
            char newChar = 'A' + g;
            i = 0;
            k = tk;
            for(int j = 0; j<s.length(); j++){
                if(s[j] != newChar){
                    k--;
                }
                if(k < 0){
                    if(s[i] != newChar){
                        k++;
                    }
                    i++;
                }
                if(k >= 0) maxLength = max(maxLength, j - i + 1);
                
            }
        }
        return maxLength;
    }
};