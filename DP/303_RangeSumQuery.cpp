//
// Created by leige on 7/12/2020.
//
// ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-303-range-sum-query-immutable/
class NumArray {
    //Runtime: 64 ms, faster than 33.30% of C++ online submissions for Range Sum Query - Immutable.
    //Memory Usage: 17.1 MB, less than 86.55% of C++ online submissions for Range Sum Query - Immutable.
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size();
        sum_ = vector<int>(n, 0);
        sum_[0] = nums[0];
        for (auto i = 1; i < n; i++)
        {
            sum_[i] = sum_[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sum_[j];
        return sum_[j] - sum_[i-1];
    }
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
