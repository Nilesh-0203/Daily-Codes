class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // Approach:
        // Count positive integers that DO NOT have any of given digits
        // Then subtract it from total possible numbers
        
        int digits = arr.size();
        bool have_zero = find(arr.begin(), arr.end(), 0) != arr.end();
        
        if (n == 1) return digits - (have_zero ? 1 : 0);
        // We subtracted one in case of zero when n = 1
        // because 0 is not a positive integer
        
        int not_have_cnt = 9 - digits;
        // number of possible value first place of number can take
        // 9 - digits because first place cannot be 0 
        
        if (have_zero)   not_have_cnt++;
        
        for (int i = 1; i < n; i++) {
            not_have_cnt *= (10 - digits);
        }

        int total_num = pow(10, n - 1) * 9;
        return total_num - not_have_cnt;
    }
};
