#define ll long long
class Solution {
public:
     bool solve(vector<vector<char>>& grid, ll row, ll col) {
        for(ll i = 0; i <= row; i++) {
            for(ll j = 0; j <= col; j++) {
                if(grid[i][j] == 'X') {
                    return true;
                }
            }
        }
        return false;
    }
    
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        vector<vector<ll>> prefix(n, vector<ll>(m, 0));
        ll count = 0;
        ll ans = 0;
        ll mini1 = INT_MAX, mini2 = INT_MAX;
        for(ll i = 0; i < n; i++) {
            prefix[i][0] = (i > 0 ? prefix[i-1][0] : 0) + (grid[i][0] == 'X' ? 1 : (grid[i][0] == 'Y' ? -1 : 0));
        }
        for(ll j = 0; j < m; j++) {
            prefix[0][j] = (j > 0 ? prefix[0][j-1] : 0) + (grid[0][j] == 'X' ? 1 : (grid[0][j] == 'Y' ? -1 : 0));
        }
        for(ll i = 1; i < n; i++) {
            for(ll j = 1; j < m; j++) {
                if(grid[i][j] == 'X') {
                    mini1 = min(mini1, (ll)i);
                    mini2 = min(mini2, (ll)j);
                }
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (grid[i][j] == 'X' ? 1 : (grid[i][j] == 'Y' ? -1 : 0));
            }
        }
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                // cout << prefix[i][j] << " ";
                if(prefix[i][j] == 0) {
                    if(solve(grid, i, j)) ans++;
                }
            }
            // cout << endl;
        }
        // cout << endl;
        return ans;
    }
};