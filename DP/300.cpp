// ref: huahua
// method 1:
class Solution {
    // time: O(n2)
    // space: O(n)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// method 2:
class Solution {
    // TIme: O(NlogN)
    // space: O(n)
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(auto ele: nums)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), ele);
            if(iter != dp.end())
            {
                size_t index = distance(dp.begin(), iter);
                dp[index] = ele;
            }
            else
                dp.push_back(ele);
        }
        return dp.size();
    }
};