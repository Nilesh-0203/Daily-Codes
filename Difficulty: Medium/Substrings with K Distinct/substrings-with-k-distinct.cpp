class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int n=s.size();
        vector<int>mp(26,0);
        vector<int>dp(26,-1);
        int j=0;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
            dp[s[i]-'a']=i;
            if(mp[s[i]-'a']==1)
            {
                ++count;
            }
            while(j<i && count>k )
            {
                --mp[s[j]-'a'];
                if(mp[s[j]-'a']==0)
                {
                    --count;
                }
                j++;
            }
            if(count<k)
            {
                continue;
            }
            int l_limit=INT_MAX;
            for(int l=0;l<26;l++)
            {
                
                if(dp[l]>=j)
                {
                  l_limit=min(l_limit,dp[l]);  
                }
            }
            ans+=(l_limit-j+1);
        }
        return ans;
    }
};