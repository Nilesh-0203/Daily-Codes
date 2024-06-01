//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        int x=0,y=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0 && (i+1)%2==1 && (v[i]%2==1)){
                y++;
            }
            else if(v[i]!=0 && (i+1)%2==0 && (v[i])%2==0){
                x++;
            }
        }
        if((x+y)%2==0){
            return "EVEN";
        }
        else{
            return "ODD";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends