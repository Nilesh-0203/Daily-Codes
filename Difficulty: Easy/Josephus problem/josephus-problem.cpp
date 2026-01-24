class Solution {
  public:
     int josephus(int n, int k) {
        // code here
        int ans=0;
       for(int i=1; i<=n; i++){
           ans=(ans+k)%i;
       }
       return ans+1;
    }
};