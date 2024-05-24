class Solution {
public:
    bool solve(int mid, vector<int>& candies, long long k) {
        for(auto val : candies) {
            k -= val / mid;
            if(k <= 0) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(mid, candies, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};
