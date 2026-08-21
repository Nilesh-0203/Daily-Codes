class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int cnt=0;
        int n=s1.size(), m=s2.size();
        if(n!=m) return -1;
        unordered_map<char,int> mp;
        for(auto i: s1) mp[i]++;
        for(auto i: s2) mp[i]--;
        for(auto i: mp){
            if(i.second!=0) return -1;
        }
        int i=n-1, j=m-1;
        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                i--;
                j--;
            }
            else{
                i--;
                cnt++;
            }
        }
        return cnt;
    }
};
