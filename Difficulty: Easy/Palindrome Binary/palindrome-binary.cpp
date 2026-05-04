class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s = bitset<32>(n).to_string();
        
        // remove leading zeros
        int i = 0;
        while (i < s.length() && s[i] == '0') i++;
        
        string trimmed = s.substr(i);  // correct
        
        // reverse string
        string rev = trimmed;
        reverse(rev.begin(), rev.end());
        
        return trimmed == rev;
        
    }
};