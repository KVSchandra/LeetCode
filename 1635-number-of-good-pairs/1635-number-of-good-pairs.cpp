class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int sum = 0;
        for(auto it : mp){
            if(it.second > 1){
                int n = it.second;
                sum += (n*(n-1)/2);
            }
        }
        return sum;
    }
};