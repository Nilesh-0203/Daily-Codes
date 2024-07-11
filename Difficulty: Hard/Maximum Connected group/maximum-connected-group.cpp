//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>>d4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
    bool is_val(int x, int y, int n, int m)
    {
        if(x < 0 || y < 0 || x >= n || y >= m)return false;
        return true;
    }
    void MarkAll(vector<vector<int>>&grid, int mark, map<int, int>&size, int i, int j, int m, int n, int &ans)
    {
        size[mark]++; grid[i][j] = mark;
        if(size[mark] > ans)ans = size[mark];
        for(auto &d : d4)
        {
            int x = i + d[0], y = j + d[1];
            if(is_val(x, y, m, n) && grid[x][y] == 1)
            {
                MarkAll(grid, mark, size, x, y, m, n, ans);
            }
        }
        return;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int mark = 2, ans = 0;
        map<int, int>size;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    // mark all 
                    MarkAll(grid, mark, size, i, j, m, n, ans);
                    mark++;
                }
            }
        }
        // for(auto &it : grid)
        // {
        //     for(auto &i : it)cout<<i<<" "; cout<<endl;
        // }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int>st;
                    for(auto &d : d4)
                    {
                        int x = i + d[0], y = j + d[1];
                        if(is_val(x, y, m, n))
                        {
                            st.insert(grid[x][y]);
                        }
                    }
                    int cur = 1;
                    for(auto &it : st)
                    {
                        cur += size[it];
                    }
                    if(cur > ans)ans = cur;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends