//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int t[100001];
    int solve(vector<int>&arr,int n, int idx){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take=arr[idx]+solve(arr,n,idx+2);
        int ntake=solve(arr,n,idx+1);
        
        return t[idx]= max(take,ntake);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,n,0);
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
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends