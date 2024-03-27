class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        int i = 0, j = 0;
        while(j < nums.size()) {
            mp[nums[j]]++;
            if(mp[0] <= 1){
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(mp[0] == 2) {
                while(mp[0] == 2) {
                    mp[nums[i]]--;
                    i++;
                }
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi-1;
    }
};