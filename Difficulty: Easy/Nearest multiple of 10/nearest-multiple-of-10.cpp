//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n=str.length();
        int lastNo=str[n-1]-'0';
        if(lastNo<=5){
            str[n-1]='0';
            return str;
        }
        str[n-1]='0';
        int i=n-2;
        while(i>=0 && str[i]=='9')
        {
            str[i]='0';
            i--;
        }
        if(i<0){//for cases like 9,99,999....
            return '1'+str;
        }
        else{
            str[i]++;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends