class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(auto val : nums1) {
            mp[val]++;
        }
        vector<int> ans;
        for(auto val : nums2) {
            if(mp.find(val) != mp.end()) {
                ans.push_back(val);
                mp[val]--;
                if(mp[val] == 0) {
                    mp.erase(val);
                }
            }
        }
        return ans;
    }
};