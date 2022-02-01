class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //两遍循环，第一遍循环找出重复的数字，第二遍循环找出应该是什么数
        //思路就是利用了数字都是从1到n的性质。利用了数组idx是1-n的特性，来辅助寻找重复的数字
        //缺点：会改变数组中的数字
        vector<int> res(2, -1);
        for(size_t i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            if(nums[abs(tmp)-1] < 0) {
                res[0] = abs(tmp);
            } else {
                nums[abs(tmp)-1] = nums[abs(tmp)-1] * (-1);
            }
        }
        
        for(size_t i = 0; i< nums.size(); i++) {
            if(nums[i] > 0)
                res[1] = i+1;
        }
        return res;
    }

};