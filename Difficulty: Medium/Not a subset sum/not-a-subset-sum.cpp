class Solution {
  public:
    int findSmallest(std::vector<int>& arr) {
        // Sort the array to process elements in increasing order
        std::sort(arr.begin(), arr.end());
        
        long long res = 1; // Start with the smallest positive integer
        
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is greater than res, 
            // res is the smallest number we cannot form.
            if (arr[i] > res) {
                break;
            }
            // Otherwise, we can form all sums up to res + arr[i] - 1
            res += arr[i];
        }
        
        return res;
    }
};