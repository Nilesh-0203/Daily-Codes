//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int nums[], int k) {
        // code here
        int left=0;
        int right=1000000001;
        if(n<k){
            return -1;
        }
        while(left<right){
            int mid=(left+right)/2;
            int i=0;
            int count=0;
            while(i<n){
                if(count==k || nums[i]>mid){
                    left=mid+1;
                    break;
                }
                int sums=0;
                while(i<n){
                    sums+=nums[i];
                    if(sums>mid)
                        break;
                    else
                        i++;
                }
                count++;
            }
            if(i==n)
                right=mid;
        }
        return right;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends