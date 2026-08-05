class Solution {
  public:
    long long countAtMost(vector<int>& arr, int limit) {
        
        if (limit < 0)
            return 0;
        
        int left = 0;
        long long sum = 0;
        long long ans = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            
            sum += arr[right];
            
            while (sum > limit) {
                sum -= arr[left];
                left++;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        
        return countAtMost(arr, r) - countAtMost(arr, l - 1);
    }
};