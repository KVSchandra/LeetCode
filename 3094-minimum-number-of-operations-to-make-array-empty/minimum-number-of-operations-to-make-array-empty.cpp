class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++) mp[nums[i]]++;
        int count = 0;
        for(auto it : mp){
            int a = it.second;
            if(it.second == 1) {count++;return -1;}
            else sum+=(it.second + 2)/3;
        }
        
        return sum;
    }
};