//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int> mp(k , -1);
    int sum =0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum +=arr[i];
        if(sum%k == 0)
        {
            ans = i+1;
        }
        int rem=sum%k;
        while(rem<0) rem+=k;
        if(mp[rem]!=-1)
        {
            int j = mp[rem] +1;
            ans = max(ans ,i-j+1);
        }
        if(mp[rem]==-1)
        {
            mp[rem] = i;
        }
        else
        {
            mp[rem] = min(mp[rem] ,i);
        }
        
    }
    
    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends