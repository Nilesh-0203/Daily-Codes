class Solution {
  public:
    int getCount(int n) {
        // code here
        int ans = 0;
        int lastRemoved = 1;
        int sum = 0;
        // Consecutive for more than half's sum will always be more than n
        int check = (n / 2);
        
        // Odd and not equal to 1
        if( ((n & 1) == 1) && n != 1 ) {
            check++;
        }
    
        // Sliding window of variable size
        for(int i = 1; i <= check; i++) {
            sum += i;
            
            while(sum >= n) {
                if(sum == n) {
                    ans++;
                }
                
                sum -= lastRemoved;
                lastRemoved++;
            }
        }
        
        return ans;
    }
};