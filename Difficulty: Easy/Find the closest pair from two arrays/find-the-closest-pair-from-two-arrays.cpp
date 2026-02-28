class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n=arr1.size(),m=arr2.size();
        int left = 0;
        int right = m-1;
        int ans = INT_MAX;
        int ans1,ans2;
        while(right >= 0 && left<n){
            int sum = arr1[left] + arr2[right];
            if(abs(sum-x) < ans){
                ans = abs(sum-x);
                ans1 = arr1[left];
                ans2 = arr2[right];
            }
            if(sum > x){
                right--;
            }
            else {
                left++;
            }
        }
        return {ans1,ans2};
    }
};