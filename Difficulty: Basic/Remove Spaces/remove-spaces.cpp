class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=' ')
                ans+=s[i];
        }
        return ans;
    }
};