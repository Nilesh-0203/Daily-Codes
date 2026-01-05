class Solution {
  public:
    int maxSubarraySum(vector<int>& Arr, int k) {
        // code here
        int n=Arr.size();
        long long max_sum=LONG_MIN;
            long long sum=0;
     for(int i=0;i<k;i++){
         sum+=Arr[i];
     }
     max_sum=sum;
     for(int i=k;i<n;i++){
         sum+=Arr[i];
         sum-=Arr[i-k];
         max_sum=max(max_sum,sum);
     }
     return max_sum;
    }
};