//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int t[1001][1001];
    long long solve(int i,int j,int arr[]){
        if(i>j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        long long takeLeft=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
        long long takeRight=arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr));
        
        return t[i][j]=max(takeLeft,takeRight);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        memset(t,-1,sizeof(t));
        return solve(0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends