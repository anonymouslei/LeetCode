// method 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 快慢指针。如果有环，那么快慢指针最终会相遇
        int slow = 0, fast = 0, t = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true) {
            // 这里可以参看力扣中文版的讲解
            slow = nums[slow];
            t = nums[t];
            if(slow == t) return t;
        }

    }
};
// method 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(auto n: nums) {
                if(n <= mid) cnt++;
            }
            if(cnt > mid)
                right = mid;
            else 
                left = mid + 1;
        }
        return right;
    }

//这道题的思路是:我们定义cnt[i]表示nums数组中小于等于i的数有多少个，假设我们重复
//的数是target,那么[1, target-1]里的所有数都满足cnt[i]<=i,[target, n]里的
//所有数都满足cnt[i]>i,具有单调性
//因此可以得知，在[1, target]中cnt[i]>i,证明重复的数字在这个区间中。
//程序中的mid可以理解为target
//? 但是还是不理解什么时候二分法应该返回right, 什么时候应该返回right
//!
};