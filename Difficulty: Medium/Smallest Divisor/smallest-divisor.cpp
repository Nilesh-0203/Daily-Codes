class Solution {
  public:
    bool solve(vector<int>&arr,int mid,int k){
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%mid==0){
                count+=arr[i]/mid;
            }
            else{
                count+=(arr[i]/mid)+1;
            }
        }
        return count<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int start=1,end=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(solve(arr,mid,k)){
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
