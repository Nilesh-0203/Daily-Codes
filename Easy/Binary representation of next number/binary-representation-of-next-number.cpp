//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string ans="";
        int carry=1;
        for(int i=s.size()-1;i>=0;i--)
        {
              int ch=(carry+(s[i]-'0'))%2 ;
                if(ch==1)
                ans+='1';
                else
                ans+='0';
                
                carry= (carry+(s[i]-'0'))/2;
        }
        if(carry==1)
        ans+='1';
        
        string temp="";
        for(int i=ans.size()-1;i>=0;i--)
        temp+=ans[i];
        
        int i=0;
        while(temp[i]=='0')
         i++;
        
         temp=temp.substr(i);
        
        return temp;
        
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
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends