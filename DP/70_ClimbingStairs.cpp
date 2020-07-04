//
// Created by lei.ge on 6/20/2020.
// ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-70-climbing-stairs/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 6 MB, less than 70.98% of C++ online submissions for Climbing Stairs.

// dp
class Solution_1 {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        int curr = 1;
        for (int i = 2; i <= n; i++) {
            curr = two + one;
            one = two;
            two = curr;
        }
        return curr;
    }
};
// iteration
class Solution {
public:
    int climbStairs(int n) {
        f_ = vector<int>(n+1, 0);
        return numOfSolutions(n);
    }
private:
    int numOfSolutions(int n) {
        if(n<=1) return 1; // 终止条件
        if(f_[n]>0) return f_[n];
        f_[n] = numOfSolutions(n-1) + numOfSolutions(n-2);
        return f_[n];
    }

    vector<int> f_;
};