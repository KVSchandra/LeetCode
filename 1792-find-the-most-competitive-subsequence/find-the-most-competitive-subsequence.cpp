class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        k = nums.size()-k;
        for(int i = 0; i<nums.size(); i++) {
            if(!st.empty() && st.top() <= nums[i]) {
                st.push(nums[i]);
            }
            else if(st.empty()) st.push(nums[i]);
            else {
                while(!st.empty() && (st.top() > nums[i]) && k) {
                    k--;
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        vector<int>ans;
        while(k--) st.pop();
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};