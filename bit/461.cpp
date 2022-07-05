class Solution {
public:
    int hammingDistance(int x, int y) {
        auto tmp = x^y;
        int res = 0;
        while(tmp)
        {
            if((tmp & 1) == 1)
            {
                res++;
            }
            tmp = tmp >> 1;
        }
        
        return res;
    }
};