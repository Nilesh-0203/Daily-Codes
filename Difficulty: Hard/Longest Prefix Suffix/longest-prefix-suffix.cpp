//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int p=0;
        int s=1;
        int cnt=0;
        int pos=1;
        int n=str.size();
        while(p<n && s<n)
        {
            if(str[p]==str[s])
            {
                cnt++;
                p++;
                s++;
            }
            else
            {
                cnt=0;
                pos++;
                s=pos;
                p=0;
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends