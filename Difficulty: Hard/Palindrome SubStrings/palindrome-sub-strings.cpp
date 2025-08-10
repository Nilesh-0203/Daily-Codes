class Solution {
  public:
    void checkPalindrome(string &s, int i, int j, int &cnt){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
            if(j-i > 2) cnt++;
        }
        
    }
    int countPS(string &s) {
        int cnt = 0;
        
        for(int i=0; i<s.length()-1; i++){
            checkPalindrome(s, i, i+1, cnt); 
            checkPalindrome(s, i, i, cnt); 
        }
        
        return cnt;
    }
};