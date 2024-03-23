class Solution {
public:
    long long solve(long long mid, vector<int> &piles) {
        long long ans = 0;
        for(int i = 0; i<piles.size(); i++) {
            ans += ceil((double)piles[i]/mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi = *max_element(piles.begin(), piles.end());
        long long low = 1, high = maxi;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(solve(mid, piles) > h) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};