class Solution {
  public:
     int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size(),ans=0,cnt=0,last=0,j=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2){
                cnt++;
                last=0;
            }
            //
            while(j<=i && cnt>=k){
                if(arr[j]%2){
                    cnt--;
                }
                j++;
                //count of sub-array
                last++;
            }
            //
            ans+=last;
        }
        //
        return ans;
    }
};