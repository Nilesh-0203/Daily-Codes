//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx,int prev,vector<int>&a,int n){
        if(idx>=n){
            return 0;
        }
        int not_take=solve(idx+1,prev,a,n);
        int take=0;
        if(prev==-1 || abs(a[idx]-a[prev])==1){
            take=1+solve(idx+1,idx,a,n);
        }
        return max(take,not_take);
        
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        return solve(0,-1,a,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends