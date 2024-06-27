//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int t[10001];
    int mod=1e9+7;
    int solve(int idx,int n){
        if(idx==n){
            return 1;
        }
        if(idx>n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take_one=solve(idx+1,n);
        int take_two=solve(idx+2,n);
        return t[idx]=(take_one+take_two)%mod;
    }
    int countWays(int n)
    {
        // your code here
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends