class Solution {
public:
    int nextIndex(int i, int n, vector<vector<int>>& jobs){
        int l = i+1;
        int h = n-1;
        int ans = n;
        while(l <= h){
            int mid = h + (l - h)/2;
            if(jobs[i][1] <= jobs[mid][0]){
                ans = mid;
                h = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    int solve(int i, int n, vector<vector<int>>&jobs, vector<int>&dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int next = nextIndex(i, n, jobs);
        int pick = jobs[i][2] + solve(next, n, jobs, dp);
        int notPick = 0 + solve(i+1, n, jobs, dp);
        return dp[i] = max(pick, notPick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>>jobs(n, vector<int>(3));
        for(int i = 0; i<n; i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        vector<int>dp(n, -1);
        sort(jobs.begin(), jobs.end());
        return solve(0, n, jobs, dp);
    }
};