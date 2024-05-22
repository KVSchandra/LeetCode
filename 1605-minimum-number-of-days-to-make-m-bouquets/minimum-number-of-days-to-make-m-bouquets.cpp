class Solution {
public:
    long long solve(long long mid, long long k, vector<int>&bloomDay) {
        long long ans = 0;
        long long count = 0;
        for(long long i = 0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                count++;
            }
            else {
                ans += count/k;
                count = 0;
            }
        }
        ans += count/k;
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high) {
            long long mid = low + (high - low)/2;
            long long a = solve((long long)mid, k, bloomDay);
            if(a >= m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};