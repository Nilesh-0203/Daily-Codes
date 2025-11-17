class Solution {
  public:
    
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        int dp[n];
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	              dp[i]=max(dp[i],dp[j]+arr[i]);   
	            }
	        }
	    }
	    int maxi=0;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,dp[i]);
	    }
	    return maxi;
    }
};