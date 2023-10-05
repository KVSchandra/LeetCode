class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            ans.push_back(nums[i] + nums[j]);
            i++;
            j--;
        }
        int maxi = *max_element(ans.begin(),ans.end());
        return maxi;
    }
};