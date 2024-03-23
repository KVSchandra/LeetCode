class Solution {
public:
    int func(int mid, vector<int>&weights) {
        int days = 1;
        int wt = 0;
        for(int i = 0; i<weights.size(); i++) {
            if(wt + weights[i] > mid) {
                days++;
                wt = weights[i];
            }
            else wt += weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end());
        int low = maxi;
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(func(mid, weights) <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};