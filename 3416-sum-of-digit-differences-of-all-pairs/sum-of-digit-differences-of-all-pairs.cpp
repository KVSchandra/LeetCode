class Solution {
public:
    long long sumDigitDifferences(std::vector<int>& nums) {
        long long sum = 0;
        long long count = 0;
        long long a = nums[0];
        while(a) {
            count++;
            a /= 10;
        }
        vector<vector<long long>> v(count, vector<long long>(10, 0));

        for(auto val : nums) {
            string s = to_string(val); 
            for(long long i = 0; i < s.size(); i++) {
                v[i][s[i] - '0']++;
            }
        }

        for(long long i = 0; i<count; i++) {
            for(long long j = 0; j < 10; j++) {
                for(long long k = j+1; k < 10; k++) {
                    sum += (v[i][j]*v[i][k]);
                }
            }
        }

        return sum;
    }
};
