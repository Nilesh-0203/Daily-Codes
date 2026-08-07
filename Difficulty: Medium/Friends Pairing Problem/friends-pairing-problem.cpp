class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        if(n == 1 || n == 2) return n;
        int pre1 = 1, pre2 = 2;
        for(int i = 3;i <= n;i++){
            int cur = pre2+pre1 * (i-1);
            pre1 = pre2;
            pre2 = cur;
        }
        return pre2;
    }
};
