//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int n;
    bool checkRow(vector<vector<int>> &arr,int i){
        int x=0,y=n-1;
        while(x<=y){
            if(arr[i][x]!=arr[i][y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    bool checkCol(vector<vector<int>> &arr,int i){
        int x=0,y=n-1;
        while(x<=y){
            if(arr[x][i]!=arr[y][i]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        n=arr.size();
        for(int i=0;i<n;i++){
            if(checkRow(arr,i)){
                return to_string(i) +" R";
            }
        }
        for(int i=0;i<n;i++){
            if(checkCol(arr,i)){
                return to_string(i) +" C";
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends