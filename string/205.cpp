class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash;
        unordered_set<char> set_table;
        for(int i = 0; i < s.size(); i++)
        {
            if(hash.count(s[i]))
            {
                if(hash[s[i]] != t[i])
                    return false;
            }
            else if(set_table.count(t[i]))
            {
                return false;
            }
            else
            {
                set_table.insert(t[i]);
                hash[s[i]] = t[i];
            }
            
        }
        return true;
    }
};