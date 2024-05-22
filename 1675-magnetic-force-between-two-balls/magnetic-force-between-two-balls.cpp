class Solution {
public:
    int solve(int mid, vector<int>&position, int m) {
        int ans = 1;
        int last = position[0];
        for(int i = 0; i < position.size(); i++) {
            if(position[i] - last >= mid) {
                ans++;
                last = position[i];
            }
            if(ans >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(solve(mid, position, m) == false) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};