class Solution {
  public:
     int n;
    vector<vector<int>> path;   // result matrix (1 = on path)
    vector<vector<int>> dead;   // dead[i][j] = 1 means "proven cannot reach end"

    bool solve(int i, int j, vector<vector<int>>& mat) {
        // Out of bounds or blocked cell
        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        // Already proven this cell cannot reach the destination -> prune
        if (dead[i][j])
            return false;

        // Reached the destination
        if (i == n - 1 && j == n - 1) {
            path[i][j] = 1;
            return true;
        }

        path[i][j] = 1;             // tentatively include this cell
        int maxJump = mat[i][j];

        // Priority: shortest jump first (step = 1,2,3,...)
        // For the same jump length: RIGHT before DOWN
        for (int step = 1; step <= maxJump; step++) {
            if (solve(i, j + step, mat)) return true;   // try RIGHT
            if (solve(i + step, j, mat)) return true;   // then DOWN
        }

        // No move from here works -> this cell is a dead end
        path[i][j] = 0;             // backtrack
        dead[i][j] = 1;             // memoize the failure
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        n = mat.size();
        path.assign(n, vector<int>(n, 0));
        dead.assign(n, vector<int>(n, 0));

        if (solve(0, 0, mat))
            return path;

        return {{-1}};              // no valid path exists
    }
};