//
// Created by LeiGe on 6/3/2020.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        // sort
        sort(nums.begin(), nums.end());

        vector<int> subset;
        dfs(nums, 0, res, subset);

        return res;
    }

private:
    void dfs(vector<int>& nums, int k, vector<vector<int>>& res, vector<int> subset) {
        // store subset element into res
        res.push_back(subset);
        // add a new element to the subset
        for(int i = k; i < nums.size(); i++) {

            if(i != k && nums[i] == nums[i-1]) {
                continue;
            }
            // put a new element into subset
            subset.push_back(nums[i]);
            // next layer search
            dfs(nums, i+1, res, subset);
            // backtrack
            subset.pop_back();
        }
    }
};

