class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //TC(N + M)
        unordered_map<int, int>mp;
        stack<int>st;
        for(int i = nums2.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto val : nums1) {
            ans.push_back(mp[val]);
        } 
        return ans;
    }
};