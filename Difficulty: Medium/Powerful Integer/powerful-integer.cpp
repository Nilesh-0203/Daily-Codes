class Solution {
  public:
     int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        int res=-1;
        map<int,int> mp;
        for(auto it:intervals)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        for(auto it:mp)
        {
            if(sum>=k && sum+it.second<k) res=it.first-1;
            sum+=it.second;
            if(sum>=k)
            {
                res=it.first;
            }
        }
        return res;
    }
};