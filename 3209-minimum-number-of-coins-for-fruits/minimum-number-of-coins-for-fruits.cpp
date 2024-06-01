class Solution {
private:
int solver(int index,vector<int>& prices,int forfree,vector<vector<int>>&dp)
{
    if(index>=prices.size())
    {
        return 0;
    }
    if(dp[index][forfree+1]!=-1)
    {
        return dp[index][forfree+1];
    }
    int pick=1e9;
    int notpick=1e9;
    int notpick1=1e9;
    if(forfree==-1 && index<prices.size())
    {
        pick=min(pick,prices[index]+solver(index+1,prices,2*(index)+1,dp));
    }
    else if(forfree>=index && index<prices.size())
    {
        pick=min(pick,prices[index]+solver(index+1,prices,2*(index)+1,dp));
        notpick=solver(index+1,prices,forfree,dp);
    }
    else if(forfree<index && index<prices.size())
    {
        pick=prices[index]+solver(index+1,prices,2*(index)+1,dp);
    }
    return dp[index][forfree+1]=min(pick,notpick);
}
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(1001,vector<int>(2003,-1));
        return solver(0,prices,-1,dp);
    }
};