class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>st;
        int mini = INT_MAX;
        for(int i = x; i<nums.size(); i++) {
            st.insert(nums[i-x]);
            auto it = st.lower_bound(nums[i]);
            if(it != st.end()) mini = min(mini, abs(nums[i] - *it));
            if(it != st.begin()) {
                it--;
                mini = min(mini, abs(nums[i] - *it));
            }
            if(mini == 0) return 0;
        }
        return mini;
    }
};