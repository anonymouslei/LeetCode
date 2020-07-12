//
// Created by leige on 7/12/2020.
//

class Solution1 {
    //Runtime: 16 ms, faster than 94.95% of C++ online submissions for Minimum Path Sum.
    //Memory Usage: 10.3 MB, less than 20.89% of C++ online submissions for Minimum Path Sum.
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n, 0));

        ans[0][0] = grid[0][0];
        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    ans[i][j] = ans[i][j-1] + grid[i][j];
                else if(j == 0)
                    ans[i][j] = ans[i-1][j] + grid[i][j];
                else
                    ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + grid[i][j];
            }
        }
        return ans[m-1][n-1];
    }
}
class Solution2 {
    // Runtime: 20 ms, faster than 71.69% of C++ online submissions for Minimum Path Sum.
    //Memory Usage: 10.3 MB, less than 22.92% of C++ online submissions for Minimum Path Sum.
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        ans_ = vector<vector<int>>(m, vector<int>(n, -1));
        ans_[0][0] = grid[0][0];
        int ans = helper(grid, m-1, n-1);
        return ans;
    }
private:
    int helper(const vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0) return INT_MAX;
        if(ans_[i][j] > -1) return ans_[i][j];
        ans_[i][j] = min(helper(grid, i-1, j), helper(grid, i, j-1)) + grid[i][j];
        return ans_[i][j];

    }
    vector<vector<int>> ans_;
};