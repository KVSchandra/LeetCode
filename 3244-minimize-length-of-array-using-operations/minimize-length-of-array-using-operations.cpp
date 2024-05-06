class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == mini) count++;
            else if(nums[i] % mini != 0) {
                return 1;
            }
        }
        return (count + 1)/2;
    }
};