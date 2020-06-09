//
// Created by LeiGe on 6/3/2020.
// ref: https://www.jiuzhang.com/solutions/subsets/#tag-highlight-lang-cpp
//
#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subsets;
        dfs(nums, 0, subsets, res);

        return res;
    }

private:
    void dfs(vector<int>& nums, int k, vector<int>& subsets, vector<vector<int>>& res) {
        // Save the current subsets to res
        res.push_back(subsets);
        // add a new element to the subset
        for(int i = k; i < nums.size(); i++) {
            subsets.push_back(nums[i]);
            // next layer search
            dfs(nums, i+1, subsets, res);
            // backtrack
            subsets.pop_back();
        }



    }
};
