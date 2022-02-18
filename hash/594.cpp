class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        //for(int i = 0; i < nums.size() ; i++)
        for(auto i: nums)
        {
            //这里不需要这么复杂，对于c++会直接付0为初值
            /*
            auto it = hash_table.find(nums[i]);
            if(it != hash_table.end())
            {
                hash_table[nums[i]] ++;
            }
            else 
            {
                hash_table[nums[i]] = 1;
            }
            */
            hash_table[i]++;
        }
        
        int res = 0;
        /*
        这里也有一些复杂了
        for(auto i: hash_table)
        {
            int key = i.first;
            int num = i.second;
            auto it = hash_table.find(key+1);
            if((it != hash_table.end()) && (res < num + (it->second)))
            {
                res = num + (it->second);
            }
        }
        */
        for(auto [key, num]: hash_table)
        {
            //count只是找出来这个元素是否存在，如果存在，则为1，如果不存在，则为0
            if(hash_table.count(key+1))
            {
                res = max(res, num+hash_table[key+1]);
            }
        }
        return res;
        
    }
};