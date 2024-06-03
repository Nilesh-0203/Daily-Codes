//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int numberOfConsecutiveOnes(int n) {
        // code here
        int a=1,b=1;
        int ans=1;
        if(n==1 || n==2){
            return 1;
        }
        for(int i=3;i<=n;i++){
            int c=(a+b)%mod;
            a=b;
            b=c;
            
            ans=((ans*2)%mod + a)%mod;
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
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends