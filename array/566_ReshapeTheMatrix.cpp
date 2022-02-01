class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int r_origin = mat.size();
        int c_origin = mat[0].size();
        if(r*c != r_origin*c_origin)
            return mat;
        
        vector<vector<int>> res;
        
        for(int i = 0; i < r; i++) {
            vector<int> tem{};
            for(int j = 0; j < c; j++) {
                int current_num = i*c+j;
                size_t row_n = current_num / c_origin;
                size_t col_n = current_num % c_origin;
                tem.push_back(mat[row_n][col_n]);
            }
            res.push_back(tem);
        }
        return res;
    }
};