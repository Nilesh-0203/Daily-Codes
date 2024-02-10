//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
     long long pathsum(vector<vector<int>>& arr, int n, int m, int k, vector<vector<vector<long long>>>& v) {
        if (n < 0 || m < 0 || k < 0) return 0;
        if (n == 0 && m == 0) return k == arr[m][n];
        if (v[m][n][k] != -1) return v[m][n][k];

        v[m][n][k] = pathsum(arr, n - 1, m, k - arr[m][n], v) + pathsum(arr, n, m - 1, k - arr[m][n], v);
        return v[m][n][k];
    }

    long long numberOfPath(int n, int k, vector<vector<int>>& arr) {
       
        vector<vector<vector<long long>>> v(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));
        
        return pathsum(arr, n - 1, n - 1, k, v);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends