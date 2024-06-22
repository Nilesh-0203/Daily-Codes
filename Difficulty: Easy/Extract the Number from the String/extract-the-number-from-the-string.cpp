//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        string ans="";
        long long maxi=-1;
        int n=sentence.length();
        for(int i=0;i<n;i++){
            if(sentence[i]>='0' && sentence[i]<='9'){
                if(sentence[i]!='9'){
                    ans+=sentence[i];
                }
                else{
                    while(i<n && sentence[i]!=' '){
                        i++;
                    }
                    ans="";
                }
            }
            if(i<n && sentence[i]==' ' && !ans.empty()){
                maxi=max(maxi,stoll(ans));
                ans="";
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends