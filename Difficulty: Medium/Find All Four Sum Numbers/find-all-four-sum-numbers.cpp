//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    set<vector<int>>st;
    int n;
    int num41,num31;
    void twoSum(vector<int>&nums,long long t,int i,int j){
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<t){
                i++;
            }
            else if(sum>t){
                j--;
            }
            else if(sum==t){
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                st.insert({num41,num31,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    void threeSum(vector<int>& nums,long long tar,int idx) {
        for(int i=idx;i<nums.size();i++){
            num31=nums[i];
            long long tat=tar-num31;
            twoSum(nums,tat,i+1,n-1);
        }
    }
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            num41=nums[i];
            long long tar=target-num41;
            threeSum(nums,tar,i+1);
        }
        vector<vector<int>>v;
        for(auto it : st){
            v.push_back(it);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends