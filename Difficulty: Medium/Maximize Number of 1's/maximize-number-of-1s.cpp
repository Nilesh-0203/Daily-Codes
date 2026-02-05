class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int last_zero = 0;
        int current = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0)current ++;
            if(current > k){
                while(arr[last_zero] != 0)last_zero ++;
                last_zero++;
                current--;
            }
                ans = max(ans,i-last_zero+1);
        }
        ans = max(ans,n-last_zero);
        return ans;
    }
};
