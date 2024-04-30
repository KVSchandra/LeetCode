class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        long long mask = 0;
        for(long long i = 0; i<word.size(); i++) {
            mask ^= (1 << (word[i]-'a'));
            count += mp[mask];
            for(long long j = 0; j<10; j++) {
                mask ^= 1 << j;
                count += mp[mask];
                mask ^= 1 << j;
            }
            mp[mask]++;
        }
        // for(auto val : mp) {
        //     bitset<10>bit(val.first);
        //     cout<<bit<<" "<<val.second<<endl;
        // }
        return count;
    }
};