class Solution {
  public:
    int isPossible(vector<int>&arr,int k,int mid){
        int cnt=0;
        int bloomCount=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt>=k){
                bloomCount++;
                cnt=0;
            }
        }
        return bloomCount;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int start=0;
        int end=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(arr,k,mid)>=m){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};