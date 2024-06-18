//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][1001];
    int solve(int arr[],int N,int target,int idx){
        if(idx>=N || target < 0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(t[idx][target]!=-1){
            return t[idx][target];
        }
        int take=solve(arr,N,target-arr[idx],idx+1);
        int not_take=solve(arr,N,target,idx+1);
        return t[idx][target]=take || not_take;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total%2==1){
            return 0;
        }
        int target=total/2;
        return solve(arr,N,target,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends