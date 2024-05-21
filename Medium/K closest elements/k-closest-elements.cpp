//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        
        for(int i=0;i<n;i++){
            if(x==arr[i]){
                continue;
            }
            if(x<arr[i]){
                pq1.push({abs(arr[i]-x),i});
            }
            else{
                pq2.push({abs(arr[i]-x),i});
            }
        }
        pq1.push({1000000007,-1});
        pq2.push({1000000007,-1});
        
        vector<int>ans;
        while(1){
            int diff1=pq1.top().first;
            int diff2=pq2.top().first;
            
            if(diff1<=diff2){
                ans.push_back(arr[pq1.top().second]);
                pq1.pop();
            }
            else{
                ans.push_back(arr[pq2.top().second]);
                pq2.pop();
            }
            if(ans.size()==k){
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends