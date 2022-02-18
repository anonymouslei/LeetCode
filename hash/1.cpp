class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i) {
            //如果对于i来说，它的res没有在hash表中发现，那么就把他存在hash表中。
            //如果它的res在hash中发现了，则直接返回res位置所存的i和当前的i
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end())
            {
                return vector<int>{i, it->second};
            }
            else 
            {
                hashtable[nums[i]] = i;
            }
        }
        return {};

    }
};