class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' ')
                ans+="%20";
            else
                ans+=s[i];
        }
        return ans;
    }
};