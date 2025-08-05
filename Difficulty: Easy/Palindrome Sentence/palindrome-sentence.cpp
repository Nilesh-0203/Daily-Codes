class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans+=s[i]+32;
            }
            else if(s[i]>='0' && s[i]<='9'){
                ans+=s[i];
            }
            else if(s[i]>='a' && s[i]<='z'){
                ans+=s[i];
            }
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        return temp==ans;
    }
};