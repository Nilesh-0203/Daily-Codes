class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
          int n=arr.size();
        int pre=1, suf=1, maxi=-1e9;
        
        for(int i=0; i<n; i++){
            pre*=arr[i];
            suf*=arr[n-i-1];
            maxi=max(maxi, max(pre, suf));
            if(arr[i]==0) pre=1;
            if(arr[n-i-1]==0) suf=1;
        }
        
        return maxi;
    }
};