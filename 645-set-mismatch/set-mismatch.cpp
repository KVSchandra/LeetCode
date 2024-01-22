class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto val : nums){
            mp[val]++;
        }
        int a, b;
        for(auto val : mp){
            if(val.second == 2) a = val.first;
        }
        for(int i = 1; i<=nums.size(); i++){
            if(mp.find(i) == mp.end()){
                b = i;
                break;
            }
        }
        return {a, b};
    }
};