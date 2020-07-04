//
// Created by leige on 7/4/2020.
//
class Solution1 {
    // Runtime: 28 ms
    //Memory Usage: 8.6 MB
    // Time complexity: O(n)
    // space complexity: O(n)
public:
    int minFlipsMonoIncr(string S) {
        int size = S.size();
        vector<int> left(size);
        vector<int> right(size);
        //if(S[0] == '1')
        //    left[0] = 1;
        left[0] = S[0] - '0';
        for (auto i = 1; i < size; i++)
            left[i] = left[i - 1] + S[i] - '0';
        //if(S[size-1] == '0')
        //    right[size-1] = 1;
        right[size - 1] = '1' - S[size - 1];
        for (auto i = size - 2; i >= 0; i--)
            right[i] = right[i + 1] + '1' - S[i];
        //int ans = S.size();
        int ans = right[0];
        for (auto i = 0; i < size - 1; i++) {
            int num = left[i] + right[i + 1];
            if (num < ans)
                ans = num;
        }
        ans = min(ans, left[size - 1]);
        return ans;
    }
};


