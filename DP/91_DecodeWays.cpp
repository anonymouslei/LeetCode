//
// Created by leige on 7/12/2020.
//
// ref: http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-91-decode-ways/


class Solution {
    //Runtime: 8 ms, faster than 18.79% of C++ online submissions for Decode Ways.
    //Memory Usage: 14.1 MB, less than 10.84% of C++ online submissions for Decode Ways.
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 1 && s[0] == '0') return 0;
        if (n == 1) return 1;

        if(s.length() == 0) return 0;
        m_ways_[""] = 1;
        return ways(s);
    }
private:
    int ways(const string& s) {
        // 首先，写结论相关的语句，相当于最底层的语句
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        // 如果有值，则返回存储的值
        if (m_ways_.count(s)) return m_ways_[s];

        int w = ways(s.substr(1)); // 开始递归
        const int prefix = stoi(s.substr(0, 2));
        // 和之前的题目不一样的是，这里没有直接把两种情况相加，而是先判断了一下第二种情况是否满足条件。
        if (prefix >=10 && prefix <= 26)
            w += ways(s.substr(2));

        m_ways_[s] = w;
        return w;
    }

    unordered_map<string, int> m_ways_;
};
