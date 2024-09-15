#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    bool solve(ll i, ll j, ll k, vector<vector<ll>>& vis, vector<vector<int>>& grid) {
        if(grid[i][j] == 1) k--;
        if(k <= 0) return false;
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            if(k > 0) return true;
            return false;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        vector<ll> dir = {0, 1, 0, -1, 0};
        for(ll m = 0; m < 4; m++) {
            ll dx = i + dir[m];
            ll dy = j + dir[m+1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && !vis[dx][dy]) {
                vis[dx][dy]++;
                if(solve(dx, dy, k, vis, grid)) {
                    return dp[i][j][k] = true;
                }
                vis[dx][dy]--;
            }
        }
        return dp[i][j][k] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<ll>> vis(grid.size(), vector<ll>(grid[0].size()));
        dp.resize(grid.size()+1, vector<vector<ll>>(grid[0].size()+1, vector<ll>(health+1, -1)));
        return solve(0, 0, health, vis, grid);
    }
};