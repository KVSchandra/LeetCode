class Solution {
public:
    bool solve(int mid, vector<int>&price, int k) {
        int ans = 1;
        int last = price[0];
        for(int i = 1; i<price.size(); i++) {
            if(price[i] - last >= mid && price[i] != last) {
                last = price[i];
                ans++;
            }
            if(ans == k) return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 1, high = price.back()-price[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(solve(mid, price, k) == false) high = mid-1;
            else low = mid + 1;
        }
        return high;
    }
};