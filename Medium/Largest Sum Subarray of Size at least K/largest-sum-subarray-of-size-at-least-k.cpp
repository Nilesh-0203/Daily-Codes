//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
    {
        // first apply kadane's algorithm to find the maximum sum of subarray at each point
        long long dp[n];
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum < 0) sum = 0;
            dp[i] = sum;
        }
        
        // now just apply sliding window with k window size
        long long maxi = -1e9;
        sum = 0;
        int i = 0, j = 0;
        while(j < n){
            sum += arr[j];
            if(j-i+1 < k) j++;
            else{
                int id = j - k;
                if(id < 0) maxi = max(maxi, sum);
                else maxi = max(maxi, sum + dp[id]);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends