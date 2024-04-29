class Solution {
public:
    int findTheLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        vector<char>vow = {'a', 'e', 'i', 'o', 'u'};
        int mask = 0;
        int maxi = INT_MIN;
        mp[0] = -1;
        for(int i = 0; i<s.size(); i++) {
            if(find(vow.begin(), vow.end(), s[i]) != vow.end()) {
                mask ^= (1 << (s[i] - 'a'));
                if(mp.find(mask) == mp.end()) {
                    mp[mask] = i;
                }
                // else {
                //     cout<<mask<<" "<<i<<endl;
                // }
            }
            maxi = max(maxi, i - mp[mask]);
        }
        return maxi;
    }
};