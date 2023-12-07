//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
  int b[n]={0};
  int c[n]={0};
     for(int i=0;i<n;i++){
         if(a[i]<=R) b[i]=1;
         if(a[i]<L) c[i]=1;
     }
     long long int  x=0,y=0;
     long long int ans=0;
     for(int i=0;i<n;i++){
         if(b[i]==1) x++;
         else {
             ans+=(x*1LL*(x+1))/2;
             x=0;
         }
     }
     if(x)ans+=(x*1LL*(x+1))/2;
     
     long long di=0;
     for(int i=0;i<n;i++){
         if(c[i]==1)y++;
         else {
             di+=(y*1LL*(y+1))/2;
             y=0;
         }
     }
     if(y) di+=(y*1LL*(y+1))/2;
     return ans-di;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends