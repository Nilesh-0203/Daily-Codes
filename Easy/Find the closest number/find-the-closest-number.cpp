//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int i=0,j=n-1;
        int ans1=0,ans2=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]<=k){
                ans1=arr[mid];
                i=mid+1;
            }
            else{
                ans2=arr[mid];
                j=mid-1;
            }
        }
        if(abs(ans1-k)<abs(ans2-k)){
            return ans1;
        }
        return ans2;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends