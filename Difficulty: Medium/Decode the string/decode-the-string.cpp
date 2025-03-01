//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int>No;
        stack<string>st;
        string result="";
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(isalpha(c)){
                result+=c;
            }
            else if(c=='['){
                st.push(result);
                No.push(num);
                result="";
                num=0;
            }
            else if(c==']'){
                int n=No.top();
                No.pop();
                string temp=st.top();
                st.pop();
                for(int i=0;i<n;i++){
                    temp+=result;
                }
                result=temp;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends