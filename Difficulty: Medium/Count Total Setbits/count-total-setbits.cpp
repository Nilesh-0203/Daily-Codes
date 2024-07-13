//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n){
    	int cnt=0;
    	while(n){
    		if(n&1){
    			cnt++;
    		}
    		n=n>>1;
    	}
    	return cnt;
    } 
    int countBits(int n) {
        // code here
        int cnt=0;
        for(int i=0;i<=n;i++){
    		cnt+=solve(i);
    	}
    	return cnt;
    }
};

//{ Driver Code Starts.
#define int long long int

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.countBits(N) << "\n";
    }
    return 0;
}
// } Driver Code Ends