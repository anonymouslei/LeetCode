class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
                    
        for (int i=matrix.size()-1, j=0; (i>=0 && j<matrix[0].size());)
        {
            if(target == matrix[i][j])
            {
                return true;
            }
            else if(target > matrix[i][j])
            {
                j++;
            }
            else
            {
                i--;
            }

        }
        return false;
    }

};