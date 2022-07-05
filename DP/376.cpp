class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int res = 1;
        int flag = 0;
        int last = nums[0];
        int tmp;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == last)
                continue;
            if(isWiggle(flag, nums[i], last))
            {
                flag = (nums[i] - last) > 0 ? 1:-1;
                res++;
                tmp = last;
                last = nums[i];
            }
            else
            {
                if(abs(nums[i] - tmp) > abs(last - tmp))
                    last = nums[i];
            }
        }
        return res;
    }
private:
    bool isWiggle(const int flag, const int current, const int last)
    {
        if(flag == 0)
            return true;
        if((flag *(current - last)) < 0)
            return true;
        else
            return false;
    }
};