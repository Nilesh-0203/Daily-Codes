//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod=1000000007;
    int t[501][501];
    int solve(int x,int y){
        if(x==0 && y==0){
            return 1;
        }
        if(x<0){
            return 0;
        }
        if(y<0){
            return 0;
        }
        if(t[x][y]!=-1){
            return t[x][y];
        }
        int left=solve(x,y-1)%mod;
        int up=solve(x-1,y)%mod;
        return t[x][y]=(left+up)%mod;
    }
    int ways(int x, int y)
    {
        //code here.
        memset(t,-1,sizeof(t));
        return solve(x,y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends