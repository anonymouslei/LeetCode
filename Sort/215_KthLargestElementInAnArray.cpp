class Solution {
// reference: https://www.youtube.com/watch?v=KUcByl1bVyg&ab_channel=%E4%B8%AD%E5%9B%BD%E5%A4%A7%E5%AD%A6MOOC-%E6%85%95%E8%AF%BE
// reference: https://www.cnblogs.com/grandyang/p/4539757.html
// Runtime: 40 ms, faster than 17.80% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10 MB, less than 71.04% of C++ online submissions for Kth Largest Element in an Array.
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true)
        {
            int pos = quickSort(nums, right, left);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }
    
    int quickSort(vector<int>& nums, int right, int left)
    {
        int quiot = nums[left], j = right, i = left;
        while(i != j)
        {
            while(i < j && nums[j] <= quiot)
                j--;
            swap(nums[i], nums[j]);
            while(i < j && nums[i] >= quiot)
                i++;
            swap(nums[i], nums[j]);
        }
        return i;        
    }
};