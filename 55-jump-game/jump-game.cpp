class Solution {
private:
bool solver(int index,vector<int>&nums,vector<int>&dp)
{
    if(index==nums.size()-1)
    {
        return true;
    }
    if(nums[index]==0)
    {
        return false;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    bool ans=false;
    for(int i=1;i<=nums[index];i++)
    {
        if(index+i <nums.size())
        {
            ans = ans|solver(index+i,nums,dp);
            if(ans == true) return dp[index] = true;
        }
    }
    return dp[index]=ans;
}
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solver(0,nums,dp);
    }
};