//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int ans=0;
    int solve(int n,int x,int y,int z,int idx,vector<int>&dp){
        if(idx==n){
            return 0;
        }
        if(idx>n){
            return INT_MIN;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take_x=1+solve(n,x,y,z,idx+x,dp);
        int take_y=1+solve(n,x,y,z,idx+y,dp);
        int take_z=1+solve(n,x,y,z,idx+z,dp);
        return dp[idx]=max(take_x,max(take_y,take_z));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int ans=solve(n,x,y,z,0,dp);
        return ans<0 ? 0:ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends