class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n<=0)return false;
        while(n>0){
            int m=n&1;
            if(m==0){
                return false;
            }
            n>>=1;
        }
        return true;
    }
};