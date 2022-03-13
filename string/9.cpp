class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        std::string s = std::to_string(x);
        unsigned int size = s.size();
        for(int i = 0; i < (size/2); i++)
        {
            if(s[i] != s[size-1-i])
                return false;
        }
        return true;
        
    }
};