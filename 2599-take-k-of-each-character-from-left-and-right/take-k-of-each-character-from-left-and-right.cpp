#define ll long long
class Solution {
public:
    bool check(map<char, ll>& mp1, map<char, ll>& mp2, ll k) {
        if((mp2['a'] - mp1['a'] < k) || (mp2['b'] - mp1['b'] < k) || (mp2['c'] - mp1['c'] < k)) return false;
        return true;
    }

    int takeCharacters(string s, int k) {
        ll n = s.size();
        map<char, ll> mp;
        map<char, ll> mp2;
        for(auto val : s) mp2[val]++;
        if(mp2['a'] < k || mp2['b'] < k || mp2['c'] < k) return -1;
        ll i = 0, j = 0;
        ll maxi = INT_MIN;
        while(j < n) {
            mp[s[j]]++;
            if(check(mp, mp2, k)) {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else {
                while(!check(mp, mp2, k) && i <= j) {
                    mp[s[i]]--;
                    i++;
                }
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return (n - maxi);
    }
};