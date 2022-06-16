class Solution {
    // Time: O(n)
    // space: O(n)
    // the first part still needs to be improved. 
    // the space complexity can be further reduced
public:
    int numDecodings(string s) {
        if(s.size() == 1)
        {
            if(s[0] == '0')
                return 0;
            else
                return 1;
        }
        if(s.size() == 2)
        {
            if(s[0] == '0')
            {
                return 0;
            }
            else
            {
                return  isEncoded(changeSToInt(s.substr(0,2))) + isEncoded(changeSToInt(s.substr(1,1))) * 1;
            }
        }
        
        std::vector<int> res(s.size()+1, 0);
        res[1] = isEncoded(changeSToInt(s.substr(0,1)));
        res[2] = isEncoded(changeSToInt(s.substr(0,2))) + isEncoded(changeSToInt(s.substr(1,1))) * res[1];
        for(int i = 3; i < s.size() + 1; i++)
        {
            int tmp1 = isEncoded(changeSToInt(s.substr(i-2,2)));
            int tmp2 = isEncoded(changeSToInt(s.substr(i-1,1)));
            res[i] = isEncoded(changeSToInt(s.substr(i-2,2))) * res[i-2] + isEncoded(changeSToInt(s.substr(i-1,1))) * res[i - 1];
        }
        
        return res[s.size()];
    }
private:
    int isEncoded(const int val)
    {
        if((val > 0) && val < 27)
        {
            return 1;
        }
        return 0;
    }
    int changeSToInt(const string& s)
    {
        if(s.size() == 1)
            return s[0]-'0';
        if(s[0] == '0')
            return 40;
        else
            return (s[0] - '0')*10 + (s[1] - '0');
    }
};