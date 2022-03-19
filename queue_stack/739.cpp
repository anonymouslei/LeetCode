class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperatures_size = temperatures.size();
        std::vector<int> res(temperatures_size, 0);
        stack<int> monotonic_stack;
        for(int i = 0; i < temperatures_size; i++)
        {
            while(monotonic_stack.size())
            {
                int current_value = monotonic_stack.top();
                if(temperatures[current_value] < temperatures[i])
                {
                    res[current_value] = i - current_value;
                    monotonic_stack.pop();
                }
                else
                {
                    break;
                }
            }
                
            if((i+1 < temperatures_size) && (temperatures[i] < temperatures[i+1]))
            {
                res[i] = 1;
            }
            else
            {
                monotonic_stack.push(i);
            }
        }
        return res;
    }
};