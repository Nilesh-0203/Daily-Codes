//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int N,M;
	int t[1001][1001];
	int solve(int i,int j,int a[],int b[],int elem){
	    if(i>=N){
	        return 0;
	    }
	    if(j>=M){
	        return 0;
	    }
	    if(t[i][j]!=-1){
	        return t[i][j];
	    }
	    int take=a[i]*b[j]+ solve(i+1,j+1,a,b,elem);
	    int not_take=0;
	    if(elem>0){
	        not_take=solve(i+1,j,a,b,elem-1);
	    }
	    return t[i][j]=max(take,not_take);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		N=n,M=m;
		memset(t,-1,sizeof(t));
		return solve(0,0,a,b,n-m);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends