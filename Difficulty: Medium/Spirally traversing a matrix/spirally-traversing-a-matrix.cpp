//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int cnt=0;

        int rowStartIndex=0;
        int rowEndIndex=row-1;
        int colStartIndex=0;
        int colEndIndex=col-1;

        while(cnt<total){
            for(int i=colStartIndex;cnt<total && i<=colEndIndex;i++){
                ans.push_back(matrix[rowStartIndex][i]);
                cnt++;
            }
            rowStartIndex++;
            for(int i=rowStartIndex;cnt<total && i<=rowEndIndex;i++){
                ans.push_back(matrix[i][colEndIndex]);
                cnt++;
            }
            colEndIndex--;
            for(int i=colEndIndex;cnt<total && i>=colStartIndex;i--){
                ans.push_back(matrix[rowEndIndex][i]);
                cnt++;
            }
            rowEndIndex--;
            for(int i=rowEndIndex;cnt<total && i>=rowStartIndex;i--){
                ans.push_back(matrix[i][colStartIndex]);
                cnt++;
            }
            colStartIndex++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends