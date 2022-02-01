class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int right = matrix.back().back();
        int left = matrix[0][0];
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            int total = 0;
            for(size_t i = 0; i < matrix.size(); i++) {
                total += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(total >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};