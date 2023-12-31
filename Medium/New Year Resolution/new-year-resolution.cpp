//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    vector<vector<int>>dp;
    
    int solve(int idx,int N,int coins[],int sum)
    {
        if(idx==N)
        {
            if(sum>0 && (sum%20==0 || sum%24==0 || sum==2024)) return true;
            else return false;
         }
        int &ans= dp[idx][sum];
        
        if(ans!=-1) return ans;
        
        return ans= solve(idx+1,N,coins,sum) || solve(idx+1,N,coins,sum+coins[idx]);
    }
    int isPossible(int N , int coins[]) 
    {
        dp.resize(N,vector<int>(2025,-1));
        return solve(0,N,coins,0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends