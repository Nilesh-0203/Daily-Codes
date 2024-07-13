//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long  prod=1;
	    long long  largest=LLONG_MIN;
	    for(int i=0;i<n;i++){
	        if(prod==1000000000){
                break;
            }
            prod*=arr[i];
            largest=max(largest,prod);
            if(prod==0){
                prod=1;
            }
	    }
	    prod=1;
	    for(int i=n-1;i>=0;i--){
	        if(prod==1000000000){
                break;
            }
            prod*=arr[i];
            largest=max(largest,prod);
            if(prod==0){
                prod=1;
            }
	    }
	    return largest;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends