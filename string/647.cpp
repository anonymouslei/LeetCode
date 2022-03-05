class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            result += spread(i, i, s);
            result += spread(i, i+1, s);
        }
        return result;
    }
    
private:
    int spread(int left, int right, const string& s)
    {
        int ans = 0;
        while((left >= 0) && (right<s.size()) &&(s[left] == s[right]))
        {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
};