//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char>st;
        for(int i = 0; i < S.size(); ++i){
            while(!st.empty() && K && (st.top() > S[i])) {
                st.pop();
                --K;
            }
            if((S[i] != '0') || !st.empty()) {
                st.push(S[i]);
            }
        }
        while(!st.empty() && K--) {
            st.pop();
        }
        
        string num = "";
        while(!st.empty()){
            num.push_back(st.top()), st.pop();
        }
        reverse(num.begin(), num.end());
        return (num == "") ? "0" : num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends