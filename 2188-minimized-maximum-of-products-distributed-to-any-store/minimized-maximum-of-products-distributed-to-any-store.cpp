class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end())+1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            auto solve = [&](int n) {
                for(auto val : quantities) {
                    n -= val/mid;
                    if(val%mid) n--;
                    if(n < 0) return false;
                }
                return true;
            };
            if(solve(n)) high = mid - 1;
            else low = mid + 1;
        } 
        return low;
    }
};