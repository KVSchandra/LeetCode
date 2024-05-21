class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        for(int i = 0; i<nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                if((nums[j] == key || nums[i] == key) && abs(i-j) <= k) {
                    if(find(ans.begin(), ans.end(), i) == ans.end()) ans.push_back(i);
                    if(find(ans.begin(), ans.end(), j) == ans.end()) ans.push_back(j);

                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};