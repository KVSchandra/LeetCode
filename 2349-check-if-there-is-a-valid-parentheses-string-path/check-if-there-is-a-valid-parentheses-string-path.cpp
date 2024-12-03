#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    bool solve(ll i, ll j, ll count, vector<vector<char>>& grid) {
        if(count < 0) return false;
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            count += (grid[i][j] == '(' ? 1 : -1);
            return (count == 0);
        }
        if(dp[i][j][count] != -1) return dp[i][j][count];
        ll right = 0, down = 0;
        if(i + 1 < grid.size()) {
            down = solve(i+1, j, count + (grid[i][j] == '(' ? 1 : -1), grid);
        }
        if(j + 1 < grid[0].size()) {
            right = solve(i, j+1, count + (grid[i][j] == '(' ? 1 : -1), grid);
        }
        return dp[i][j][count] = (right || down);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<ll>>(m, vector<ll>(n+m, -1)));
        return solve(0, 0, 0, grid);
    }
};