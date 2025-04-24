//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        vector<int>ans(32);
        for(int ele: arr) {
            for(int i = 0; i < 32; i++) {
                if((ele&(1<<i)) != 0) {
                    ans[i]+=1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i]%3!=0) {
                res|=(1<<i);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends