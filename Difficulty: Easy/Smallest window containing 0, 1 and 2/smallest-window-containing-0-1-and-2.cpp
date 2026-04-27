class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size();
        int one = 0;
        int zero = 0, two = 0;
        int l = 0, r = 0, mini = INT_MAX;
        while(r<n){
            if(s[r]=='0') zero++;
            else if(s[r]=='1') one++;
            else if(s[r]=='2') two++;
            
            while(zero>=1 && one>=1 && two>=1)
            { 
                mini = min(mini,(r-l+1));
               if(s[l]=='0') zero--;
               else if(s[l]=='1') one--;
               else if(s[l]=='2') two--;
               l++;
            }

            r++;
        }
        return (mini==INT_MAX) ? -1 : mini;
    }
};
