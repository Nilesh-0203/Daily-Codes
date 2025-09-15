class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int m=pat.size(),n=tar.size();
        int i=m-1,j=n-1;
        int matchidx=m;
        while(i>=0 && j>=0){
            if(pat[i]==tar[j]){
                int diff=matchidx-i;
                if(diff%2==1){
                    matchidx=i;
                    j--;
                }
            }
            i--;
        }
        if(j<0)return true;
        return false;
        
    }
};