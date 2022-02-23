class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_table;
        for(const int i: nums)
        {
            hash_table.insert(i);
        }
        int length = 0;
        for(auto i: hash_table)
        {
            if(hash_table.count(i-1))
            {
                continue;
            }
            else 
            {
                int tmp_length = 1;
                int curr = i;
                while(hash_table.count(++curr))
                {
                    tmp_length++;
                }
                if(tmp_length > length)
                    length = tmp_length;
            }
        }
        return length;
    }
};