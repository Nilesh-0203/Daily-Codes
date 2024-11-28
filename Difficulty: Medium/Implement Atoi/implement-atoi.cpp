//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i=0;
   while(s[i]!='\0' && s[i]==' '){
       i++;
   }
   int sign=1;
   if(s[i]=='+' || s[i]=='-'){
       sign=1-2*(s[i++]=='-');
   }
   int base=0;
  while(s[i]>='0' && s[i]<='9' && s[i]!='\0'){
      if(base>INT_MAX/10 || (base==INT_MAX/10 && s[i]>'7')){
          return sign==1?INT_MAX:INT_MIN;
      }
      base=base*10+(s[i++]-'0');
  }
    return base*sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends