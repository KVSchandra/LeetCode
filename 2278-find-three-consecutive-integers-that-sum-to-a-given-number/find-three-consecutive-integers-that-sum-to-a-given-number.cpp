class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3 == 0) {
            long long a = num/3;
            return {a-1, a, a+1};
        }
        return {};
    }
};