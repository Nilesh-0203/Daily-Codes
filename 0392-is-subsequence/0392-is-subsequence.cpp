class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count=0;
        int j=0;
        for(int i=0;i<t.length();i++){
            if(s[j]==t[i]){
                count++;
                j++;
            }
        }
        return count >= s.length();
    }
};