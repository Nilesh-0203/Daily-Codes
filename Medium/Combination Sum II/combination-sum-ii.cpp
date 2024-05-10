//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>>result;
    int N;
    void solve(int idx,vector<int>&arr,int k,vector<int>&temp){
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(idx>=N || k < 0){
            return;
        }
        temp.push_back(arr[idx]);
        solve(idx+1,arr,k-arr[idx],temp);
        temp.pop_back();
        while(idx<arr.size()-1 && arr[idx]==arr[idx+1]) idx++;
        solve(idx+1,arr,k,temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        N=n;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        solve(0,arr,k,temp);
        return result;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends