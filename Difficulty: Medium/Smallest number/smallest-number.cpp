//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        int start=pow(10,d-1);
        int end=pow(10,d)-1;
        for(int i=start;i<=end;i++){
            int num=i;
            int sum=0;
            while(num){
                sum+=num%10;
                num=num/10;
            }
            if(sum==s){
                return to_string(i);
            }
        }
        return "-1";
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends