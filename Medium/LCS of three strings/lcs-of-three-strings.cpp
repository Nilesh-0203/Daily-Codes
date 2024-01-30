//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int N1,N2,N3;
        int t[21][21][21];
        int solve(string &A,string &B,string &C,int i,int j,int k){
            if(i>=N1 || j>=N2 || k>=N3){
                return 0;
            }
            if(t[i][j][k]!=-1){
                return t[i][j][k];
            }
            if(A[i]==B[j] && B[j]==C[k]){
                return t[i][j][k]=1+solve(A,B,C,i+1,j+1,k+1);
            }
            int a=solve(A,B,C,i,j+1,k);
            int b=solve(A,B,C,i+1,j,k);
            int c=solve(A,B,C,i,j,k+1);
            int d=solve(A,B,C,i+1,j+1,k);
            int e=solve(A,B,C,i,j+1,k+1);
            int f=solve(A,B,C,i+1,j,k+1);
            
            return t[i][j][k]= max(a,max(b,max(c,max(d,max(e,f)))));
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            N1=n1,N2=n2,N3=n3;
            memset(t,-1,sizeof(t));
            return solve(A,B,C,0,0,0);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends