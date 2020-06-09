//
// Created by hljge on 6/7/2020.
//
#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};