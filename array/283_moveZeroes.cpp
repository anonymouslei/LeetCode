class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); i++)
        {
            if(nums.at(i))
            {
                swap(nums.at(i), nums.at(j++));
            }
        }
    }

};