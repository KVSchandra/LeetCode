class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1) return nums;
        vector<int>ans;
        if(n >= 3){
            for(int i = 1; i<nums.size()-1; i++){
                if(nums[i+1] - nums[i] == 0 || nums[i+1] - nums[i] == 1 || nums[i] - nums[i-1] == 0 || nums[i] - nums[i-1] == 1) continue;
                else ans.push_back(nums[i]);
            }
        }
        if(nums[0] - nums[1] != -1 && nums[0] != nums[1]) ans.push_back(nums[0]);
        if(nums[n-1] - nums[n-2] != 1 && nums[n-1] != nums[n-2]) ans.push_back(nums[n-1]);
        return ans;
    }
};