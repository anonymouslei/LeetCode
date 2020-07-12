//
// Created by leige on 7/11/2020.
//

class Solution {
    // Runtime: 4 ms, faster than 50.40% of C++ online submissions for House Robber II.
    //Memory Usage: 7.7 MB, less than 99.80% of C++ online submissions for House Robber II.
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n < 3) return *max_element(nums.begin(), nums.end());
        return max(helper(nums, 0, n-1),helper(nums, 1, n));
    }
private:
    int helper(const vector<int> &nums, int start, int end)
    {
        int ans;
        int tmp1 = nums[start];
        int tmp2 = max(nums[start], nums[start + 1]);
        if(end - start <= 2) return tmp2;
        for (auto i = start + 2; i < end; i++) {
            ans = max(tmp1 + nums[i], tmp2);
            tmp1 = tmp2;
            tmp2 = ans;
        }
        return ans;
    }
};