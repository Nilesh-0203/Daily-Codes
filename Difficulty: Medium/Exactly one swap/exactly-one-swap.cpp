class Solution {
  public:
    int countStrings(string &s) {
        // code here
        unordered_map<int,int>mp;
        bool flag=false;
        
        for(int i=0;i<s.length();i++){
            if(!flag && mp.find(s[i])!=mp.end()){
                flag=true;
            }
            mp[s[i]]++;
        }
        
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]--;
            ans+=s.length()-(i+1)-mp[s[i]];
        }
        return flag==true ? ans+1:ans;
    }
};
