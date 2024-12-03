#define ll long long

static bool cmp(vector<int>& a, vector<int>& b) {
    if(a[1] != b[1]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    ll findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        vector<ll> vis(tasks.back()[1] + 2);
        for(auto& val : tasks) {
            ll temp = val[2];
            for(ll i = val[0]; i <= val[1]; i++) {
                if(vis[i]) {
                    temp--;
                    if(temp == 0) break;
                }
            }
            if(temp) {
                for(ll i = val[1]; i >= val[0]; i--) {
                    if(!vis[i]) {
                        vis[i]++;
                        temp--;
                        if(temp == 0) break;
                    }
                }
            }
        }
        ll ans = 0;
        for(auto val : vis) {
            if(val) {
                ans++;
            }
        }
        return ans;
    }
};