class Solution {
  public:
    int n;

    int check(int t, vector<int>&arr){{
      int x=0;

      for(int i=0; i<n; i++){
        if((arr[i]%t)==0){
            x+=(arr[i]/t);
        }else x+=((arr[i]+t)/t);
      }

      return x;
    }}

    int kokoEat(vector<int>& arr, int k) {
        // Code here
        n=arr.size();

        int lo=1, hi=0;

        for(int i=0; i<n; i++){
          hi=max(hi, arr[i]);
        }

        int ans=hi;

        while(lo<=hi){
          int mid=lo+(hi-lo)/2;
          if(check(mid, arr)<=k){
            ans=mid;
            hi=mid-1;
          }else lo=mid+1;
        }

        return ans;
    }
};