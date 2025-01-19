//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int touchedXaxis(vector<int>& arr) {
        // code here
        int prev=0;
        int curr=0;
        int res=0;
        for(int i=0;i<arr.size();i++){
            prev=curr;
            curr+=arr[i];
            if((prev<0 && curr>=0) || (prev>0 && curr<=0)){
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        int num;
        stringstream ss(line);
        vector<int> arr;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.touchedXaxis(arr);
        cout << ans << endl;
        cout << "~\n";
    }
}
// } Driver Code Ends