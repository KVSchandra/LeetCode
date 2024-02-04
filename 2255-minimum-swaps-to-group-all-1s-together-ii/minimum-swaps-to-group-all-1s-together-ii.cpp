class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int>mp;
        int mini = INT_MAX;
        int k = accumulate(nums.begin(), nums.end(), 0);
        for(int a = 0; a<k; a++){
            nums.push_back(nums[a]);
        }
        int count = 0;
        if(k == 0) return 0;
        while(j < n+k){
            mp[nums[j]]++;
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                mini = min(mini, mp[0]);
                mp[nums[i]]--;
                i++;
                j++;
            }
        }
        return mini;
    }
};