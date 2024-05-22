class Solution {
public:
    long long solve(int mid, vector<int>&weights) {
        int ans = 1;
        int count = 0;
        for(auto val : weights) {
            if(count + val > mid) {
                count = 0;
                ans++;
                if(val > mid) return 1e9;
                count += val;
            }
            else count += val;
        }
        return ans;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *min_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0ll);
        while(low <= high) {
            int mid = low + (high - low)/2;
            long long a = solve(mid, weights);
            if(a <= days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};