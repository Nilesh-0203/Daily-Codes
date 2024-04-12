//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     long long pairAndSum(int n, long long arr[]) {
        // code here
        long long ans = 0;
        long long p = 1;
        
        for(int i=0;i<32;i++){
            long long oneCount = 0;
            for(int j=0;j<n;j++){
                if(arr[j]&1)
                    oneCount++;
                arr[j] = arr[j]>>1;
            }
            ans += (oneCount*(oneCount-1))/2 * p;
            p = p*2;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends