class Solution {
  public:
     int f(string &s,int k){
        vector<int> c(26,0);
        int i =0;
        int j =0;
        int cnt =0;
        int ccnt =0;
        int n =s.size();
        while(j < n){
            if(c[s[j]-'a']){
                c[s[j]-'a']++;
            }else{
                c[s[j]-'a']++;
                ccnt++;
            }
            while(i <= j && ccnt == k){
                c[s[i]-'a']--;
                if(c[s[i]-'a'] == 0){
                    ccnt--;
                }
                i++;
                cnt+=(n-j);
            }
            j++;
        }
        return cnt;
    }
    int countSubstr(string& s, int k) {
        // code here
        return f(s,k)-f(s,k+1);
    }
};