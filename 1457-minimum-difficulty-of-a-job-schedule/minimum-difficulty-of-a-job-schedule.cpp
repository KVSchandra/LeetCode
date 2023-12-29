class Solution {
public:
     int solve(vector<int>& jobs, int ind, int d, int maxi, vector<vector<vector<int>>>&dp) {
         if (d == 1) return *max_element(jobs.begin() + ind, jobs.end());
         if(ind > jobs.size()-d) return INT_MAX;
         if(dp[ind][d][maxi] != -1) return dp[ind][d][maxi];
         maxi = max(maxi, jobs[ind]);
         int pick = maxi + solve(jobs, ind + 1, d - 1, 0, dp);
         int not_pick = solve(jobs, ind + 1, d, maxi, dp);
         return dp[ind][d][maxi] = min(pick, not_pick);
     }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        int n = jobDifficulty.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(d+1, vector<int>(1001, -1)));
        return solve(jobDifficulty, 0, d, 0, dp);
    }
};