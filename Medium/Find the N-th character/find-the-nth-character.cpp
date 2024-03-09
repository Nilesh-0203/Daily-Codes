//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        string str(n+1,0), temp(n+1,0);
    
         for(int i = 0; i<=n; i++) str[i] = s[i];
         

         while(r--)
         {   int j = 0;
             for(int i = 0; i<=n/2; i++)
             {
                 char fir , sec;
                 if(str[i] == '0')
                 {
                     fir = '0'; sec = '1';
                 }
                 else
                 {
                     fir = '1'; sec = '0';
                 }
                 temp[j++] = fir;
                if(j<=n) temp[j++] = sec;
             }
             str = temp;
         }
         return str[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends