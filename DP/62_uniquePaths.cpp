//
// Created by leige on 7/4/2020.
// ref : huahua

class Solution1 {
    // Recursive
    // Runtime: 12 ms, faster than 15.90% of C++ online submissions for Unique Paths.
    //Memory Usage: 8.5 MB, less than 5.01% of C++ online submissions for Unique Paths.
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n ==1)
            return 1;
        if (numOfPath_[m][n] > 0)
            return numOfPath_[m][n];
        numOfPath_[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        return numOfPath_[m][n];
    }

private:
    unordered_map<int, unordered_map<int, int>> numOfPath_; // 没有采用vector,因为vector需要初始化。
};

class Solution2 {
    // Runtime: 4 ms, faster than 15.90% of C++ online submissions for Unique Paths.
    //Memory Usage: 6.5 MB, less than 29.11% of C++ online submissions for Unique Paths.
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> numOfPaths = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        numOfPaths[1][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j<= n; ++j)
            {
                if (i == 1 && j == 1)
                {
                    continue;
                }
                else {
                    numOfPaths[i][j] = numOfPaths[i-1][j] + numOfPaths[i][j - 1];
                }
            }
        return numOfPaths[m][n];
    }
};

class Solution2 {
    //    Runtime: 80 ms
    // Memory Usage: 17.4 MB
public:
    int minFlipsMonoIncr(string S) {
        //int n = S.size();
        const int n = S.size();
        vector<vector<int>> ans = vector<vector<int>>(n+1, vector<int>(2));
        for(auto i = 1; i <= n; i++)
        {
            if(S[i - 1] == '0')
            {
                ans[i][0] = ans[i-1][0];
                ans[i][1] = min(ans[i-1][0], ans[i-1][1]) + 1;
            }
            else
            {
                ans[i][0] = ans[i-1][0] + 1;
                ans[i][1] = min(ans[i-1][0], ans[i-1][1]);
            }
        }
        return min(ans[n][0], ans[n][1]);
    }
};

class Solution3 {
    // Runtime: 16 ms
    //Memory Usage: 7.1 MB
public:
    int minFlipsMonoIncr(string S) {
        //int n = S.size();
        const int n = S.size();
        //vector<vector<int>> ans = vector<vector<int>>(n+1, vector<int>(2));
        int ans0 = 0;
        int ans1 = 0;
        for(auto i = 1; i <= n; i++)
        {
            int tmp = ans0;
            ans0 = ans0 + S[i-1] - '0';
            ans1 = min(tmp, ans1) + '1' - S[i - 1];
        }
        return min(ans0, ans1);
    }
};