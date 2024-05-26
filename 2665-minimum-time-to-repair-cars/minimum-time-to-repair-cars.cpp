class Solution {
public:
    bool solve(long long mid, vector<int>&ranks, long long n) {
        for(long long i = 0; i<ranks.size(); i++) {
            n -= (long long)(sqrt(mid/ranks[i])*1.0);
            if(n <= 0) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        long long n = cars;
        long long low = 0, high = (long long)ranks[0]*n*n;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(solve(mid, ranks, cars)) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};