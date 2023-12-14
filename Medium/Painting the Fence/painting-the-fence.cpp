//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{
    public:
     long long countWays(int n, int k){
        if(n == 1)
            return k;
            
        long long same = 0, diff = k;
        for(int i = 2; i <= n; i++) {
            long long prev = same;
            same = diff;
            diff = ((prev + same) * (k - 1)) % mod;
        }
        
        return (same + diff) % mod;
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
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends