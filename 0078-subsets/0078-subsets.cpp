class Solution {
public:
    void sub(int ind,vector<int>&nums,vector<vector<int>>&v,vector<int>&output,int n){
        if(ind == n){
            v.push_back(output);
            return;
        }

        output.push_back(nums[ind]);
        sub(ind+1,nums,v,output,n);
        output.pop_back();
        sub(ind+1,nums,v,output,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>output;
        int n = nums.size();
        sub(0,nums,v,output,n);
        return v;
    }
};