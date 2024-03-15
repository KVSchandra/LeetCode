class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        int neg = 0;
        int prod = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) count++;
            if(nums[i] < 0) neg++;
            prod*=nums[i];
        }
        
        if(count == 1){
            prod = 1;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == 0) continue;
                prod*=nums[i];
            }
        }
        vector<int>ans;
        if(count == 0){
            for(int i = 0;i<nums.size();i++){
                if(neg & 1 == 0){
                    if(nums[i] < 0) ans.push_back((-1)*prod/nums[i]);
                }
                else {
                    ans.push_back(prod/nums[i]);
                }
            }
        }
        else if(count == 1){
            for(int i = 0;i<nums.size();i++){
                if(nums[i]!=0) ans.push_back(0);
                else ans.push_back(prod);
            }
        }
        else for(int i = 0;i<nums.size();i++) ans.push_back(0);
        return ans;
    }
};