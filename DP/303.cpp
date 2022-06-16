// huahua

// solution 1:
// time: O(m * n) space: O(n)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = std::move(nums);
       
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i< right+1; i++)
        {
            sum += nums_[i];
        }
        return sum;
        
    }
private:
    vector<int> nums_;
        
};

// solution 2
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums_ = vector<int>(nums.size(), 0);
        sums_[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            sums_[i] = sums_[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return sums_[right];
        else
            return sums_[right] - sums_[left - 1];
    }
private:
    vector<int> sums_;
    // time: O(m) + n*O(1) = O(m + n), space: O(n)
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */