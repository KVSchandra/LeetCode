class Solution {
public:
    bool check(int mid, int m, int k, vector<int>&bloomDay) {
        int count = 0;
        int bouquet = 0;
        for(int i = 0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                count++;
            }
            else {
                bouquet += count/k;
                count = 0;
            }
        }
        bouquet += count/k;
        if(bouquet >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid, m, k, bloomDay)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};