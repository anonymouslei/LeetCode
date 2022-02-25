class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> hash_table1;
        unordered_map<char, int> hash_table2;
        for(auto i: s)
            hash_table1[i]++;
        for(auto i: t)
            hash_table2[i]++;
        for(auto [key, value]: hash_table1)
        {
            if(value == hash_table2[key])
                continue;
            return false;
        }
        return true;
    }
};