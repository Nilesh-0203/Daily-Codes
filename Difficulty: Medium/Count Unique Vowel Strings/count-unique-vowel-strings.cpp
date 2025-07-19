class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        map<char,int>mp;
        for(char ch:s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                mp[ch]++;
        }
        int n=mp.size();
        int ans=n;
        for(int i=2;i<n;i++){
            ans*=i;
        }
        for(auto i:mp){
            ans*=i.second;
        }
        return ans;
    }
};