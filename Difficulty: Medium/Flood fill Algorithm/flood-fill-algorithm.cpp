//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    void dfs(vector<vector<int>>&mat,int sr,int sc,int& OriginalColor,int& newColor){
        if(sr<0 || sc<0 || sr>=m || sc>=n || mat[sr][sc]!=OriginalColor || mat[sr][sc]==newColor){
            return;
        }
        mat[sr][sc]=newColor;
        for(auto dir:directions){
            int new_sr=dir[0]+sr;
            int new_sc=dir[1]+sc;
            
            dfs(mat,new_sr,new_sc,OriginalColor,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        vector<vector<int>>mat=image;
        m=mat.size();
        n=mat[0].size();
        int OriginalColor=mat[sr][sc];
        dfs(mat,sr,sc,OriginalColor,newColor);
        return mat;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends