//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
         vector<int>a;
         for(int i=0;i<n;i++){
             a.push_back(arr[i]*i);
         }
         vector<int>k;
         int ans=0;
         for(int i=0;i<n;i++){
             int r=upper_bound(k.begin(),k.end(),a[i])-k.begin();
             r=k.size()-r;
             ans+=r;
             k.insert(upper_bound(k.begin(),k.end(),a[i]),a[i]);
             
         }
         return ans;
    }
};

//{ Driver Code Starts.
// Driver code
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
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends