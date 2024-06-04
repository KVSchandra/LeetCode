class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        long long k = k1 + k2;
        map<long long, long long>mp;
        for(int i = 0; i<nums1.size(); i++) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        while(k && !mp.empty()) {
            auto val = *prev(mp.end());
            if(val.first == 0) break;
            int a = val.second;
            if(a >= k) {
                mp[val.first] -= k;
                mp[val.first-1] += k;
                break;
            }
            else {
                mp.erase(val.first);
                mp[val.first-1] += a;
                k -= a;
            }
        }
        for(auto val : mp) {
            ans += ((val.first*val.first) * val.second);
        }
        return ans;
    }
};