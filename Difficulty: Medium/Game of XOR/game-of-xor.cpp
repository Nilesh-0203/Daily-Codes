class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int ind = i+1;
            int count = ind*(n-i);
            if(count % 2 != 0) ans ^= arr[i];
        }
        return ans;
    }
};