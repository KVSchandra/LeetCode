class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = 100000;
        for(int i = 0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(target - sum) < abs(target - closest)) closest = sum; 
                if(sum > target) k--;
                else j++;
            }
        }
        return closest;
    }
};