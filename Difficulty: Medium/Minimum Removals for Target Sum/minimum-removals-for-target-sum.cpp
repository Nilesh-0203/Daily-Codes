//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
int minRemovals(vector<int> &arr, int k) {
        // code here
        int total=accumulate(arr.begin(),arr.end(),0);
        if(total==k)return arr.size();
        
        int mx=0,curr=0,n=arr.size(),tar=total-k,l=0,r=0;
        while(r<n){
            curr+=arr[r];
            r++;
            while(curr>tar && l<r){
                curr-=arr[l];
                l++;
            }
            if(curr==tar)mx=max(mx,r-l);
        }
        return mx==0?-1:n-mx;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr = inputLine();
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        int ans = obj.minRemovals(arr, k);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends