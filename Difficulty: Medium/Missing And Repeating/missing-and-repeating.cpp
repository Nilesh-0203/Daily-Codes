//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        int misNum=0;
        int repeat=0;
        for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;
        
        for(int i=1;i<=arr.size();i++){
            if(mp.find(i)!=mp.end()){
                if(mp[i]==2)
                repeat=i;
                mp.erase(i);
            }
            else
            misNum=i;
        }
        return {repeat,misNum};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends