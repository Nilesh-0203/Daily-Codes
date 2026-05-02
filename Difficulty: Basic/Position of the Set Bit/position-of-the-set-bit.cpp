class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n &(n-1)){
            return -1;
        }
        return __builtin_popcount(n-1)+1;
    }
};