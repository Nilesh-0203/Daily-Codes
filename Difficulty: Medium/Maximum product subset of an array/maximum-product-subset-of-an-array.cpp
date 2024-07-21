//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int ans=1;
        int n=arr.size();
        int mod=1e9+7;
        int mini=INT_MIN;
        int zeros=0,nCount=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeros++;
                continue;
            }
            if(arr[i]<0){
                nCount++;
                mini=max(mini,arr[i]);
            }
            ans=(ans%mod * arr[i]%mod)%mod;
        }
        if(nCount==1 && zeros+nCount==n){
            return 0;
        }
        if(nCount%2){
            ans/=mini;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends