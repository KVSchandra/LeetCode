class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long mini = INT_MAX;
        long long count = 0;
        for(auto val : matrix) {
            for(auto val1 : val) {
                sum += abs(val1);
                mini = min(mini, (long long)abs(val1));
                if(val1 < 0) count++;
            }
        }
        if(count&1) sum -= 2*mini;
        return sum;
    }
};