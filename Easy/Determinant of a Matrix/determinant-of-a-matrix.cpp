//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> matrix, int n)
{   
    if(n == 1){
        return matrix[0][0];
    }
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    else
    {
        int cof = 1;
        int det = 0;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> submat(n - 1, vector<int>(n - 1, 0));
            int rx = 0;
            for (int j = 1; j < n; j++)
            {
                rx = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    submat[j - 1][rx] = matrix[j][k];  // Adjust index here
                    rx++;
                }
            }
            int detprev = determinantOfMatrix(submat, n - 1);
            det += cof * detprev * matrix[0][i];
            cof *= -1;
        }
        return det;
    }
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends