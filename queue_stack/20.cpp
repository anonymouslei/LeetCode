class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)
            return false;
        unordered_map<char, char> dict{{'(',')'},
                                           {'{','}'},
                                           {'[',']'}};
        // 也可以不用unordered_map的方法，直接使用ascii码的方法。他们再ascii中相差1或者2
        stack<char> value;
        value.push(s[0]);
        for(int i = 1; i < s.size(); i++)
        {
            if((value.empty()) || dict[value.top()] != s[i])
            {
                value.push(s[i]);
            }
            else
            {
                value.pop();
            }
        }
        return value.empty();

    }
};