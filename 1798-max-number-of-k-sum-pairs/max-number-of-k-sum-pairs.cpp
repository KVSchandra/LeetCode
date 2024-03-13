class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        long long count1 = 0, count2 = 0;
        unordered_set<long long>st;
        for(auto val : nums) st.insert(val);
        for(auto val : st){
            if(k - val < val) continue;
            long long a = std::count(nums.begin(), nums.end(), val);
            long long b = std::count(nums.begin(), nums.end(), k - val);
            if(val != k - val){
                count1 += min(a, b);
            }
            else count2 += floor(a/2);
        }
        // count1 /= 2;
        return count1 + count2;
    }
};