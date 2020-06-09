//
// Created by hljge on 6/7/2020.
//

#include <vector>
#include <algorithm>

using namespace std;
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