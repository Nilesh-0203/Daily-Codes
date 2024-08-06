//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        string ans="";
        int cnt=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0' && cnt==0 && ans==""){
                return false;
            }
            if(str[i]!='.'){
                ans+=str[i];
            }
            else if(str[i]=='.' && ans!=""){
                int num=stoi(ans);
                if(num>=0 && num<=255){
                    cnt++;
                }
                ans="";
            }
            else{
                return false;
            }
        }
        int num=stoi(ans);
        if(num>=0 && num<=255){
            cnt++;
        }
        return cnt==4 ? true : false;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends