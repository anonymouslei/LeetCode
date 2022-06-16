class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // Time: O(n) + O(m)
        // Space: O(m)
        //其实不用那么麻烦，不需要那个vector,直接在循环里做就行，如果大于3就直接计算
        if(nums.size() < 3)
            return 0;
        int second = nums[1];
        int difference = second - nums[0];
        int num = 2;
        for(int i = 2; i < nums.size(); i++)
        {
            if((nums[i] - second) == difference)
            {
                num += 1;
            }
            else
            {
                if(num >= 3)
                {
                    num_of_contiguous_sub_.emplace_back(num);
                }
                num = 2;
                difference = nums[i] - second;
            }
            second = nums[i];
        }
        if(num >= 3)
        {
            num_of_contiguous_sub_.emplace_back(num);
        }
        int sum = 0;
        for(auto& num: num_of_contiguous_sub_)
        {
            sum += (num-1) * (num-2)/2;
        }
        return sum;
    }
    std::vector<int> num_of_contiguous_sub_;
};