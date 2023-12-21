//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        int ans = N,i=1;
        
        while(i<N){
            
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int inc=0;
            while(i<N&&ratings[i]>ratings[i-1]){
                inc++;
                ans += inc;
                i++;
            }
            int dec=0;
            while(i<N&&ratings[i]<ratings[i-1]){
                dec++;
                ans += dec;
                i++;
            }
            
            ans -= min(dec,inc);
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends