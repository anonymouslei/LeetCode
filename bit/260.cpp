class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(auto item: nums)
        {
            tmp ^= item;
        }
        int lsb = (tmp == INT_MIN) ? INT_MIN : tmp &(-tmp);
        int res1 = 0;
        int res2 = 0;
        for(auto item: nums)
        {
            if(item & lsb)
            {
                res1 ^= item;
            }
            else
            {
                res2 ^= item;
            }
        }
        return {res1, res2};
    }
};
