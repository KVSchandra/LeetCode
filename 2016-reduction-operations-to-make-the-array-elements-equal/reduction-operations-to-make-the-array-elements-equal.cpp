class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int count = 0;
        for(int i = 0; i<nums.size()-1; i++) {
            if(nums[i+1] < nums[i]) {
                count += (i+1);
            }
        }
        return count;
    }
};
