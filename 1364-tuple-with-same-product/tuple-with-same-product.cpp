class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size()-1; i++) {
            int a = nums[i];
            for(int j = i+1; j<nums.size(); j++) {
                mp[a*nums[j]]++;
            }
        }
        for(auto val : mp) {
            if(val.second > 1) {
                int a = val.second*(val.second-1)/2;
                count += 8*a;
            }
        }
        return count;
    }
};