class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto val : nums) {
            for(int i = 2; i*i <= val; i++) {
                if(val%i == 0) {
                    mp[i]++;
                    while(val%i == 0) {
                        val /= i;
                    }
                }
            }
            if(val != 1) mp[val]++;
        }
        return mp.size();
    }
};