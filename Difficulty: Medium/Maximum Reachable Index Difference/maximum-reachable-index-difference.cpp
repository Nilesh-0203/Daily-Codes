class Solution {
  public:
     int maxIndexDifference(string &s) {
        int ans = -1 , start = -1;
        bool vis[26] = {false};
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                if(vis[s[i] - 'a'])
                    continue;
                ans = 0 , start = i;
                vis[s[i] - 'a'] = true;
            }else{
                char prev = char((s[i] - 'a') + 96);
                if(vis[s[i] - 'a'] || vis[prev - 'a'])
                    ans = max(ans , i - start) , vis[s[i] - 'a'] = true;
            }
        }
        return ans;
    }
};
