class Solution {
public:
    bool solve(int mid, int m, vector<int> &position) {
        int magnets = 1;
        int last = position[0];
        for(int i = 1; i<position.size(); i++) {
            if(position[i] - last >= mid) {
                last = position[i];
                magnets++;
                if(magnets == m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position[0];
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(solve(mid, m, position) == true) {
                low = mid+1;
            }
            else high = mid-1;
        }
        return low-1;
    }
};