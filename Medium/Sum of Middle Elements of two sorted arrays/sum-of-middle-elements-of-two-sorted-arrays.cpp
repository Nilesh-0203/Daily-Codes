//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            int i=0,j=0,count=-1;
            vector<int>v;
            while(count!=n && i<n && j<n){
                if(ar1[i]<ar2[j]){
                    v.push_back(ar1[i++]);
                }
                else{
                    v.push_back(ar2[j++]);
                }
                count++;
            }
            while(count!=n && i<n){
                v.push_back(ar1[i++]);
                count++;
                
            }
            while(count!=n && j<n){
                v.push_back(ar2[j++]);
                count++;
            }
            return v[count]+v[count-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends