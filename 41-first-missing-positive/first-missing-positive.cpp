class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto val : nums) {
            mp[val]++;
        }
        for(int i = 1; i<=100001; i++){
            if(mp.find(i) == mp.end()) return i;
        }
        return -1;
    }
};