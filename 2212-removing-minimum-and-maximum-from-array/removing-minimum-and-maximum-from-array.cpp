class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int x = -1, y = -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(mini > nums[i]) {
                mini = nums[i];
                x = i;
            }
            if(maxi < nums[i]) {
                maxi = nums[i];
                y = i;
            }
        }
        if(x == y) {
            return 1;
        }
        int a = min(x, y), b = max(x, y);
        return min({abs((int)nums.size()-a), b+1, a + 1 + abs(b - (int)nums.size())});
    }
};