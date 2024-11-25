//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int prod=1;
        int largest=INT_MIN;
        int n=arr.size();
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
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends