//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        for(int cir=0,n=mat.size();cir<(n+1)/2;cir++)
        for(int i=cir;i<n-cir-1;i++)
        {
            int temp = mat[i][n-cir-1];
            mat[i][n-cir-1] = mat[n-cir-1][n-1-i];
            mat[n-cir-1][n-1-i] = mat[n-1-i][cir];
            mat[n-1-i][cir] = mat[cir][i];
            mat[cir][i] = temp;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends