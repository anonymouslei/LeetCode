//
// Created by hljge on 6/7/2020.
//

#include <vector>
#include <algorithm>

using namespace std;
// Solution 1 Brute force
//Runtime: 20 ms, faster than 11.17% of C++ online submissions for Sqrt(x).
//Memory Usage: 5.9 MB, less than 89.04% of C++ online submissions for Sqrt(x).
class Solution {
public:
    int mySqrt(int x) {
        if (x <=1) return x;
        for (long long s = 1; s <=x; s++) {
            if (s * s > x) {
                return s - 1;
            }
        }
        return -1;
    }
};
// Solution 2 binary search
// Runtime: 0 ms
//Memory Usage: 5.8 MB
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) {
            return -1;
        }
        if (x <= 1) {
            return x;
        }
        int start = 0, end = x;
        long long mid;
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if (mid * mid < x) {
                start = mid;
            } else if (mid * mid > x) {
                end = mid;
            } else {
                return (int)mid;
            }
        }
        if (end == x / end) {
            return end;
        }
        return start;
    }
};

// solution 3: Newton's method
class Solution {
public:
    int mySqrt(int a) {
        constexpr double epsilon = 1e-2;
        double x = a;
        while (x * x - a > epsilon) {
            x = (x + a / x) / 2.0;
        }
        return x;
    }
};