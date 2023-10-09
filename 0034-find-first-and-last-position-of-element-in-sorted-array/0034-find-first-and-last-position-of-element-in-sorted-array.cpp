class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a,count=0;
        if(nums.size()==1 && nums[0]==target) return {0,0};
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){ a=i;count++;}
        }
        if(count>=2)
        return {a-count+1,a};
        else if(count==1) return {a,a};
        else return{-1,-1};
    }
};