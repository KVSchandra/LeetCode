class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = 0;
        while(j < nums.size()) {
            if(nums[j] - nums[i] > k) {
                count++;
                i = j;
            }
            j++;
        }
        return count+1;
    }
};