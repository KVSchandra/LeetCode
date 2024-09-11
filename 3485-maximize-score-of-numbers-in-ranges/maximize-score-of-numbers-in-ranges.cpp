#define ll long long

class Solution {
public:
    bool check(ll mid, vector<pair<ll, ll>>& v, ll d) {
        // for(ll j = v[0].first; j <= v[0].second; j++) {
            ll prev = v[0].first;
            ll temp = 0;
            bool f = false;
            for(ll i = 1; i < v.size(); i++) {
                bool a = false;
                if(prev + mid >= v[i].first && prev + mid <= v[i].second) {
                    prev += mid;
                    f = true;
                }
                else if(prev + mid < v[i].first) prev = v[i].first;
                else return false;
            }
            // if(f == false)
                return true;
        // }
        // return false;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        vector<pair<ll, ll>> v;
        for(auto val : start) {
            v.push_back({val, val+d});
        }
        sort(v.begin(), v.end());
        ll low = 0, high = (v.back().second - v[0].first + 1);
        // for(auto val : v) {
        //     cout << val.first << " " << val.second << endl;
        // }
        
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check(mid, v, d)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};