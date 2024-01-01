//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[nums[i]%k]++;
        
        for(auto x: mp)
        {
            int r1= x.first;
            int r2= k- r1;
            
            if( r1*2== k || r1== 0){
                if(mp[r1]%2 != 0) return false;
            }
            else{
                if(mp[r2] != mp[r1]) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends