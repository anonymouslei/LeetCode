//
// Created by leige on 7/5/2020.
//

class Solution1 { // Recursion
    //Runtime: 4 ms, faster than 46.50% of C++ online submissions for House Robber.
    //Memory Usage: 8.3 MB, less than 5.14% of C++ online submissions for House Robber.
    // Time complexity: O(n)
    //
    //Space complexity: O(n)
public:
    int rob(vector<int>& nums) {
        //int size = nums.size();
        const int size = nums.size();
        int ans;
        money_ = vector<int>(size, -1);
        ans = helper(size - 1, nums);
        return ans;
    }

private:
    int helper(int n, const vector<int>& nums)
    {
        if (n < 0) return 0;
        if(money_[n] >= 0) return money_[n];
        money_[n] = max(helper(n-1, nums), helper(n-2, nums) + nums[n]);
        return money_[n];
    }
    vector<int> money_;
};

class Solution2 {
    // Runtime: 4 ms
    //Memory Usage: 7.9 MB
    // Time complexity: O(n)
    //
    //Space complexity: O(n)
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> moneys = vector<int>(n, -1);
        if (n==0)
            return 0;
        // if(n < 3) return *max_element(nums.begin(), nums.end());
        //moneys[0] = nums[0];
        //moneys[1] = max(nums[1], nums[0]);
        //for(auto i = 2; i < n; i++)
        for(auto i = 0; i < n; i++)
        {
            moneys[i] = max((i > 1 ? moneys[i-2] : 0) + nums[i],
                            (i > 0 ? moneys[i-1] :0));
            // moneys[i] = max(moneys[i-1], moneys[i-2] + nums[i]);
        }
        // return moneys[n-1];
        return moneys.back();
    }
};