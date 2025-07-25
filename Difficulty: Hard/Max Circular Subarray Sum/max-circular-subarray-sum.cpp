class Solution {
  public:
    int kadans_max(vector<int> &arr,int num){
        int sum=arr[0];
        int maxSum=arr[0];
        for(int i=1;i<num;i++){
            sum=max(sum+arr[i],arr[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
    int kadans_min(vector<int> &arr,int num){
        int sum=arr[0];
        int minSum=arr[0];
        for(int i=1;i<num;i++){
            sum=min(sum+arr[i],arr[i]);
            minSum=min(minSum,sum);
        }
        return minSum;
    }

    int maxCircularSum(vector<int> &arr) {
        // code here
        int num=arr.size();
        int total=accumulate(arr.begin(),arr.end(),0);
        int maxSum=kadans_max(arr,num);
        int minSum=kadans_min(arr,num);
        if(maxSum>0){
            return max(maxSum,total-minSum);
        }
        return maxSum;
    }
};