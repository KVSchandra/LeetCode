class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        multiset<int>st;
        int i = 0, j = 0;
        // while(j < k) {
        //     if(nums[j] < 0) {
        //         st.insert(nums[j]);
        //     }
        //     j++;
        // }
        while(j < nums.size()) {
            if(nums[j] < 0) st.insert(nums[j]);
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                // for(auto val : st) cout << val << " ";
                // cout << endl;
                if(st.size() >= x) {
                    int a = x;
                    for(auto val : st) {
                        a--;
                        if(a == 0) {
                            ans.push_back(val);
                            break;
                        }
                    }
                }
                else {
                    ans.push_back(0);
                }
                if(nums[i] < 0) {
                    auto it = st.find(nums[i]);
                    if(it != st.end()) st.erase(it);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};