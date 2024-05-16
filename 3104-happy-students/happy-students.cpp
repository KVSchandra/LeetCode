class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = 0;
        while(j < nums.size()) {
            if(j+1 < nums.size() && nums[j] < j+1 && j+1 < nums[j+1]) {
                count++;
            }
            j++;
        }
        if(nums[0] != 0) count++;
        return count+1;
    }
};