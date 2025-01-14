//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int n=nums.size();
        
        unordered_map<int, int> mp;
        
        int i=0, j=0;
        
        int c=0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(i<=j && mp.size()>k){
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            
            c += (j-i+1);
            
            j++;
        }
        
        return c;
    }
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return countSubarraysWithAtMostKDistinct(arr,k)-countSubarraysWithAtMostKDistinct(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.exactlyK(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends