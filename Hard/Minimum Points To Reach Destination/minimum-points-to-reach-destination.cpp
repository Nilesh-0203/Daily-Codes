//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int M,N;
	int t[1001][1001];
	int solve(int i,int j,vector<vector<int>>&points){
	    if(i>=M || j>=N){
	        return INT_MAX;
	    }
	    if(t[i][j]!=-1){
	        return t[i][j];
	    }
	    if(i==M-1 && j==N-1){
	        return points[i][j];
	    }
	    int right=points[i][j]+solve(i+1,j,points);
	    int down=points[i][j]+solve(i,j+1,points);
	    right=min(right,0);
	    down=min(down,0);
	    return t[i][j]=max(right,down);
	}
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    M=m,N=n;
	    memset(t,-1,sizeof(t));
	    return abs(solve(0,0,points))+1;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends