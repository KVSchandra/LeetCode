#define ll long long

class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(), skills.end());
        set<ll> st;
        ll count = 0;
        ll i = 0, j = skills.size()-1;
        while(i <= j) {
            st.insert(skills[i] + skills[j]);
            count += (skills[i] * skills[j]);
            i++, j--;
            if(st.size() > 1) return -1;
        }
        return count;
    }
};