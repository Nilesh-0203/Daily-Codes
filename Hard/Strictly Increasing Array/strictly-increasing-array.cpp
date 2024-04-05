//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int LIS(vector<int>&arr,int n){
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && arr[i]-arr[j] >= i-j){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    int min_operations(vector<int>& nums) {
        // Code here
        int n=nums.size();
        int m=LIS(nums,n);
        return n-m;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends