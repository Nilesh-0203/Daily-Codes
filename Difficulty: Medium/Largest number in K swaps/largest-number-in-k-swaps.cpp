//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    void solve(int idx,string&s,string&ans,int k){
        if(k==0 || idx>=s.length()){
            ans=max(ans,s);
            return;
        }
        char mx=s[idx];
        for(int i=idx;i<s.length();i++){
            if(i==idx){
                solve(idx+1,s,ans,k);
            }
            if(s[i]>mx){
                swap(s[i],s[idx]);
                solve(idx+1,s,ans,k-1);
                swap(s[i],s[idx]);
            }
        }
    }
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans;
        int idx=0;
        solve(idx,s,ans,k);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends