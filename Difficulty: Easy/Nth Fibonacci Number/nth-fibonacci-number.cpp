//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n==0){
                return 0;
        }
        else if(n==1){
                return 1;
        }
        else{
                int a=0,b=1;
                for(int i=0;i<n-1;i++){
                        int c=a+b;
                        a=b;
                        b=c;
                }
                return b;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends