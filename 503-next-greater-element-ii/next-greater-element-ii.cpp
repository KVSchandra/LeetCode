class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums.push_back(nums[i]);
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            bool flag = false;
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j] > nums[i]){
                    flag = true;
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(flag == false) ans.push_back(-1);
        }
        return ans;
    }
};