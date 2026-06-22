class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = (int)height.size();
        if (n < 2) return 0;

        int left = 0;
        int right = n - 1;
        long long best = 0;

        while (left + 1 < right) {
            long long width = right - left - 1;
            long long current = 1LL * min(height[left], height[right]) * width;
            if (current > best) best = current;

            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return (int)best;
    }
};