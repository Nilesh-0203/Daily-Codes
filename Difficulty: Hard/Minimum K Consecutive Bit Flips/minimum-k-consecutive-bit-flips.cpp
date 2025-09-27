class Solution {
  public:
    int kBitFlips(vector<int>& nums, int k) {
        // code here
        int n = nums.size();
        int flips = 0;  // This will keep track of the number of flips performed
        int j = 0;  // This will be used to track if the current position is flipped

        for (int i = 0; i < n; i++) {
            // If we've passed the first k elements, we need to check if the position i - k was flipped
            if (i >= k) {
                // If nums[i - k] was flipped, we toggle j
                if (nums[i - k] == 2) {
                    j ^= 1;
                }
            }

            // If we're in a position where we can still flip k bits (i.e., within the bounds)
            if ((nums[i] ^ j) == 0) {
                // If after accounting for previous flips, nums[i] is 0, we need to flip
                if (i + k > n) {
                    // If flipping would go out of bounds, it's impossible to flip the remaining bits
                    return -1;
                }

                // Perform the flip
                flips++;
                j ^= 1;  // Toggle j to indicate the flip
                nums[i] = 2;  // Mark the current position as flipped
            }
        }

        return flips;
    }
};