class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        map<int, int>mp;
        mp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i=0; i<arr.size(); i++)
        {
            preSum += arr[i];
            int remove = preSum - k;
            cnt += mp[remove];
            mp[preSum] += 1;
        }
        return cnt;
    }
};