class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash_table;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hash_table.find(nums[i]);
            if(it != hash_table.end())
            {
                return true;
            }
            hash_table[nums[i]] = i;
        }
        return false;
    }
};