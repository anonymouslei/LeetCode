class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(size_t i = 0; i <= nums.size(); i++)
        {
            res ^= i;
        }
        for(auto i: nums)
        {
            res ^= i;
        }
        return res;
    }
};