class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1] && ((i&1) == 0)) {
                nums.erase(nums.begin()+i);
                i--;
                count++;
            } 
        }
        if(nums.size() & 1) count++;
        return count;
    }
};