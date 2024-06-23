#define ll long long
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size(); 
        ll x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    x1 = i;
                    break;
                }
            }
        }
        for(ll i = n-1; i >= 0; i--) {
            for(ll j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    x2 = i;
                    break;
                }
            }
        }
        for(ll j = 0; j < m; j++) {
            for(ll i = 0; i < n; i++) {
                if(grid[i][j] == 1) {
                    y1 = j;
                    break;
                }
            }
        }
        for(ll j = m-1; j >= 0; j--) {
            for(ll i = 0; i < n; i++) {
                if(grid[i][j] == 1) {
                    y2 = j;
                    break;
                }
            }
        }
        // cout << x1 << " " << x2 << endl;
        // cout << y1 << " " << y2 << endl;
        // cout << endl;
        return (abs(y1-y2) + 1) * (abs(x1-x2)+1);
     }
};