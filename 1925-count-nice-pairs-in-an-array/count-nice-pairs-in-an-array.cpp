class Solution {
public:
    long long mod = 1e9+7;

    long long rev(long long n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<long long, long long>mp;
        for(auto val : nums ) {
            long long a = val - rev(val);
            mp[a]++;
        }
        for(auto val : mp) {
            count = (count + (long long)(val.second*(val.second-1))/2)%mod;
        }
        return count;
    }
};