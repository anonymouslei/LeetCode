class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> hash_table;
        for(const auto i: s)
        {
            hash_table[i - 'a']++;
        }
        bool simple_flag = false;
        int res = 0;
        for(const auto [key, i]: hash_table)
        {
            if(i%2 == 0)
            {
                res += i;
            }
            else if(!simple_flag)
            {
                res += i;                 
                simple_flag = true;
            }
            else
            {
                res += i-1;                 
            }
        }
        return res;
    }
};